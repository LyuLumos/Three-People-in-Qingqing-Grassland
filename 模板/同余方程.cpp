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
    if(c%d!=0) return -1; ///�����޽�����
    ll x,y;
    exgcd(a,b,x,y); ///��չŷ�������ax+by=gcd(a,b)��һ���ؽ�
    x = x*(c/d); ///�õ�ax+by=c��һ���ؽ�
    ///x+k*(b/d)��ͨ��
    x = (x%(b/d)+(b/d))%(b/d);///�õ�ģ�����µ���С������
    return x;
}

