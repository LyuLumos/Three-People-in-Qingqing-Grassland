void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0; return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}
ll Remainder(ll *m,ll *a,int n)  ///输入模数，余数，方程数
{
    m[0] = 1;
    ll p = 0,_m = 1,x,y;
    bool bo = 1;
    for(int i=1;i<=n;++i)
    {
        _m = lcm(_m,m[i-1]);  ///_m为前i-1个数的最小公倍数
        ll d = __gcd(_m,m[i]);
        if(((a[i]-p)%d+d)%d !=0){bo=0; break;}  ///判定前i个同余方程组成的方程组是否有解
        exgcd(_m,m[i],x,y);  ///用exgcd求解ax+by=gcd(a,b)的一个特解
        ll tmp = m[i]/d;
        x = x*((a[i]-p)/d); ///转化为ax+by=a[i]-p的一个特解
        x = (x%tmp+tmp)%tmp;    ///得到ax+by=a[i]-p的最小正整数解
        p = p + x*_m;  ///更新前i个方程的解
    }
    if(bo)
    {
        return p;
    }
    return -1;
}
