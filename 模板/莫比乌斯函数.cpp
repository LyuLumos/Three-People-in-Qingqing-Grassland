
///分解质因数得到单个值
int miu(int n)
{
    int p[20],c[20],m=0;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            p[++m]=i,c[m]=0;
            while(n%i==0) n/=i,c[m]++;
            if(c[m]>1) return 0;
        }
    }
    if(n>1) p[++m]=n,c[m]=1;
    return m&1?-1:1;
}

///线性得到1~n的miu值
int miu[maxn],v[maxn];
void miu(int n)
{
    for(int i=1;i<=n;++i) miu[i]=1,v[i]=0;
    for(int i=2;i<=n;++i)
    {
        if(v[i]) continue;
        miu[i]=-1;
        for(int j=2*i;j<=n;j+=i)
        {
            v[j]=1;
            if((j/i)%i==0) miu[j]=0;
            else miu[j]*=-1;
        }
    }
}
