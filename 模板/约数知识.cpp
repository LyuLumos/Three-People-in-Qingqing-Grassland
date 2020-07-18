#include<bits/stdc++.h>
using namespace std;

///��һ����������Լ�� O(N^1/2)
///����: һ������Լ�������Ͻ�Ϊ2*����n
void factors(int n)
{
    int factor[200005],m=0;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            factor[++m] = i;
            if(i!= n/i) factor[++m] = n/i;
        }
    }
}

///��1~n������Լ�� O(nlogn)
void factors(int n)
{
    vector<int>factor[maxn];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n/i;++j)
        {
            factor[i*j].push_back(i);
        }
    }
}
