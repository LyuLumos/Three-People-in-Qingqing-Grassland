#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn = 1005;
///求单个欧拉值 分解质因数的同时顺便求欧拉值
int phi(int n)
{
    int ans = n;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            ans = ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans = ans/n*(n-1);
    return ans;
}


///求1~n的欧拉值 O(n)
int v[maxn],prime[maxn],phi[maxn];
void eular(int n)
{
    memset(v,0,sizeof v);
    int cnt = 0;
    for(int i=2;i<=n;++i)
    {
        if(!v[i])
        {
            v[i]=i, prime[++cnt] = i, phi[i]=i-1;
        }
        for(int j=1;j<=cnt;++j)
        {
            if(prime[j]>v[i] || prime[j]>n/i) break;
            v[i*prime[j]] = prime[j];
            phi[i*prime[j]] = phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
        }
    }
}

int main()
{

}
