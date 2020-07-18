///算术基本定理：任何大于1的整数都能被分解为若干质数的乘积
void divide(int n)
{
    int maxm = (int)sqrt(n);
    int p[maxm],c[maxm];
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            p[++m]=i,c[m]=0;
            while(n%i==0) n/=i,++c[m];
        }
    }
    if(n>1) p[++m]=n,c[m]=1; ///说明n是质数
    ///输出尝试
    for(int i=1;i<=m;++i)
    {
        printf("%d^%d ",p[i],c[i]);
    }
}

///dfs枚举所有约数(需先质因数分解)
///m表示不同质因数的个数
int num = 0; ///约数的个数
void DFS(int x,ll now)
{
    if(x==m+1)
    {
        factor[++num] = now; return;
    }
    for(int i=0;i<=c[x];++i)
    {
        DFS(x+1,now*1LL*(ll)pow(p[x],i));
    }
}
