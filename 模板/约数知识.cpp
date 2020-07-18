#include<bits/stdc++.h>
using namespace std;

///求一个数的所有约数 O(N^1/2)
///推论: 一个数的约数个数上界为2*根号n
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

///求1~n的所有约数 O(nlogn)
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
