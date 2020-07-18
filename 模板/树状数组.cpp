int a[maxn],c[maxn]; ///a[i]记录序列值，c[i]记录[i-lowbit(i)+1,i]中所有数的和

int ask(int x)  ///查询1~x的前缀和 O(logn)
{
    int ans = 0;
    for(;x;x-=(x&-x)) ans+=c[x];
    return ans;
}
void add(int x,int y) ///单点增加a[x]+y O(logn)
{
    for(;x<=n;x+=(x&-x)) c[x]+=y;
}
int query(int k)  ///O(logn)查询第k小
{
    int ans=0,sum=0;
    for(int i=20;i>=0;--i)
    {
        if(ans+(1<<i)<=n && sum+c[ans+(1<<i)]<k)
        {
            sum+=c[ans+(1<<i)];
            ans+=(1<<i);
        }
    }
    return ans+1;
}
void init(int n) ///初始化树状数组 O(nlogn)
{
    for(int i=1;i<=n;++i) c[i] = 0;
    for(int i=1;i<=n;++i) add(i,a[i]);
}

int fun()  ///求逆序对数 O((n+m)logm)  ,c[i] 表示范围在[1,i]内的数个数
{
    ///特别要注意c数组的初始化范围和add时的终止条件
    for(int i=n;i>=1;--i)
    {
        ans+=ask(a[i]-1);  ///累加i+1~n中小于a[i]的个数
        add(a[i],1);
    }
    return ans;
}
