
int gcd(int a,int b)
{
    return b?exgcd(b,a%b):a;
}

///��չŷ�����
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0; return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}

