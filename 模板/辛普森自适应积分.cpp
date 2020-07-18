inline double f(double x)
{
    /*��������ʽ*/
}
inline double simpson(double l,double r)
{
    double mid=(l+r)/2.0;
    return (f(l)+4.0*f(mid)+f(r))*(r-l)/6.0;
}
inline double solve(double l,double r,double eps)
{
    double mid=(l+r)/2.0;
    double s=simpson(l,r),sl=simpson(l,mid),sr=simpson(mid,r);
    if(std::fabs(sl+sr-s)<=15.0*eps) return (sl+sr+(sl+sr-s)/15.0);
    return solve(l,mid,eps/2.0)+solve(mid,r,eps/2.0);
}
