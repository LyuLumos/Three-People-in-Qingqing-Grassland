void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0; return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
ll tongyu(ll a,ll b,ll c)
{
    ll d = __gcd(a,b);
    if(c%d!=0) return -1; ///返回无解的情况
    ll x,y;
    exgcd(a,b,x,y); ///扩展欧几里得求ax+by=gcd(a,b)的一个特解
    x = x*(c/d); ///得到ax+by=c的一个特解
    ///x+k*(b/d)是通解
    x = (x%(b/d)+(b/d))%(b/d);///得到模意义下的最小整数解
    return x;
}

