///���������
///������
while(r-l>1)
{
    int mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
} ///r���Ǵ�

///ʵ�������
while(r-l>eps)
{
    int mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
} ///r���Ǵ�

for(int i=0;i<100;++i)
{
    int mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
}
