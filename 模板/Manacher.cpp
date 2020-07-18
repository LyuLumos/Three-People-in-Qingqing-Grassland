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
const double eps=1e-8;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int n,m;
char s[maxn];
char t[maxn*2];
int p[maxn*2];  ///×î³¤»ØÎÄ°ë¾¶
int manacher(char *s)
{
    t[0] = '$',t[1] = '#';
    int cnt = 1;
    for(int i=1;i<=n;++i)
    {
        t[++cnt] = s[i];
        t[++cnt] = '#';
    }
    int len = strlen(t);
    int right=0,center=0,maxlen=1,maxcenter=0;
    for(int i=1;i<len;++i)
    {
        int mirror = 2*center - i;
        p[i] = i>=right ? 1 : min(right-i,p[mirror]);
        while(t[i+p[i]] == t[i-p[i]]) {
            ++p[i];
        }
        /*
        while(t[i+p[i]] == t[i-p[i]]  && t[i-p[i]]<=t[i-p[i]+2]) {
            ++p[i];
        }最长不减回文串*/
        if(p[i] + i >right) {
            right = p[i] + i;
            center = i;
        }
        if(p[i] > maxlen)
        {
            maxlen = p[i], maxcenter = i;
        }
    }
    int start = (maxcenter - p[maxcenter])>>1;
    ///s[start~start+maxlen-2]
    return maxlen-1;
}
int main()
{
    int ncase = 1;
    while(~scanf("%s",s+1))
    {
        if(!strcmp(s+1,"END")) break;
        n = strlen(s+1);
        printf("Case %d: %d\n",ncase++,manacher(s));
        memset(s,0,sizeof s);
        memset(t,0,sizeof t);
        memset(p,0,sizeof p);
    }
    return 0;
}
