#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const int inf = 0x3f3f3f3f;
ll qpow(ll a,ll b,ll mod){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod; a=a*a%mod;} ans=(ans%mod+mod)%mod;return ans;}
///小步大步算法求解高次同余方程
ll bsgs(ll a,ll b,ll p)
{
    b%=p;
       ///特判
    map<ll,ll>hash; hash.clear();
    int t = (int)sqrt(p)+1;
    for(ll j=0;j<t;++j)
    {
        ll tmp = b*qpow(a,j,p)%p;
        hash[tmp] = j;
    }
    a = qpow(a,t,p);
    if(a==0) return b==0?1:-1;
    for(ll i=0;i<=t;++i)
    {
        int tmp = qpow(a,i,p);
        int j = hash.count(tmp)?hash[tmp]:-1;
        if(j==-1) continue;
        if(i*t-j>=0) return i*t-j;
    }
    return -1;
}
int main()
{
    ll a,b,p;
    scanf("%lld%lld%lld",&p,&a,&b);
    ll ans = bsgs(a,b,p);
    if(ans==-1) puts("no solution");
    else printf("%lld\n",ans);
}
