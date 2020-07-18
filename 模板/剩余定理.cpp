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
ll Remainder(ll *m,ll *a,int n)  ///����ģ����������������
{
    m[0] = 1;
    ll p = 0,_m = 1,x,y;
    bool bo = 1;
    for(int i=1;i<=n;++i)
    {
        _m = lcm(_m,m[i-1]);  ///_mΪǰi-1��������С������
        ll d = __gcd(_m,m[i]);
        if(((a[i]-p)%d+d)%d !=0){bo=0; break;}  ///�ж�ǰi��ͬ�෽����ɵķ������Ƿ��н�
        exgcd(_m,m[i],x,y);  ///��exgcd���ax+by=gcd(a,b)��һ���ؽ�
        ll tmp = m[i]/d;
        x = x*((a[i]-p)/d); ///ת��Ϊax+by=a[i]-p��һ���ؽ�
        x = (x%tmp+tmp)%tmp;    ///�õ�ax+by=a[i]-p����С��������
        p = p + x*_m;  ///����ǰi�����̵Ľ�
    }
    if(bo)
    {
        return p;
    }
    return -1;
}
