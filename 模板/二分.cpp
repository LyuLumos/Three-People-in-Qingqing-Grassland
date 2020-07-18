///整数域二分
///开区间
while(r-l>1)
{
    int mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
} ///r即是答案

///实数域二分
while(r-l>eps)
{
    int mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
} ///r即是答案

for(int i=0;i<100;++i)
{
    int mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
}
