#include<bits/stdc++.h>
using namespace std;

///ɸ��1 O(NloglongN)
bool v[maxn];
int prime[maxn];
void primes(int n)
{
    int cnt = 0;
    memset(v,0,sizeof v); ///��ʼ�������������Ϊ����
    for(int i=2;i<=n;++i) ///ɨ��2~n������
    {
        if(v[i]) continue; ///����Ǻ����ͼ���
        prime[++cnt] = i; ///�����������
        for(int j=i;j<=n/i;++j) v[i*j] = 1; ///���䱶�����Ϊ����
    }
}

///ɸ��2 O(N)
int v[maxn]; ///��¼��i����С������ ���v[i]=i˵��i������
int prime[maxn];
void primes(int n)
{
    int cnt = 0;
    memset(v,0,sizeof v);
    for(int i=2;i<=n;++i)
    {
        if(!v[i]){v[i]=i; prime[++cnt]=i;} ///������¼
        for(int j=1;j<=cnt;++j)
        {
            if(prime[j]>v[i] ||  prime[j]>n/i) break;
            v[i*prime[j]] = prime[j];
        }
    }
}




///�����ж�
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
