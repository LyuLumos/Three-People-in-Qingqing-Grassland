#include<bits/stdc++.h>
using namespace std;

///筛法1 O(NloglongN)
bool v[maxn];
int prime[maxn];
void primes(int n)
{
    int cnt = 0;
    memset(v,0,sizeof v); ///初始将所有数都标记为质数
    for(int i=2;i<=n;++i) ///扫描2~n的质数
    {
        if(v[i]) continue; ///如果是合数就继续
        prime[++cnt] = i; ///否则就是质数
        for(int j=i;j<=n/i;++j) v[i*j] = 1; ///给其倍数标记为合数
    }
}

///筛法2 O(N)
int v[maxn]; ///记录数i的最小质因子 如果v[i]=i说明i是质数
int prime[maxn];
void primes(int n)
{
    int cnt = 0;
    memset(v,0,sizeof v);
    for(int i=2;i<=n;++i)
    {
        if(!v[i]){v[i]=i; prime[++cnt]=i;} ///质数记录
        for(int j=1;j<=cnt;++j)
        {
            if(prime[j]>v[i] ||  prime[j]>n/i) break;
            v[i*prime[j]] = prime[j];
        }
    }
}




///质数判定
bool check(int n)
{
    if(n<2) return false;
    for(int i=2;1LL*i*i<=n;++i)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{

}
