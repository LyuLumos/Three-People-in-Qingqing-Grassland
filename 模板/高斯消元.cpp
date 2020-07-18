int Gauss(double c[][N],double b[N])
{
    int rc=0,rcb=0;///初始化秩为0
    ///高斯消元过程
    ///c矩阵表示系数矩阵，b矩阵表示常数矩阵
    for(int i=1;i<=n;++i)
    {
        ///找到一行x[i]的系数最大，然后将这一行与第i行互换
        ///因为前i-1行已经处理完成所以从第i行开始往下找
        int r = i;
        for(int j=i;j<=n;++j)
        {
            if(fabs(c[j][i])>fabs(c[r][i]))
            {
                r = j;
            }
        }
            if(r!=i)
            {
                for(int k=1;k<=n;++k) swap(c[r][k],c[i][k]);
                swap(b[r],b[i]);
            }
            if(fabs(c[i][i])<eps) { continue;}
        ///将第i列除第i行外的其余行系数全变为0
        for(int j=1;j<=n;++j)
        {
            if(j==i) continue;
            double rate = c[j][i]/c[i][i];
            for(int k=1;k<=n;++k) c[j][k]-=c[i][k]*rate;
            b[j]-=b[i]*rate;
        }
    }
    for(int i=1;i<=n;++i)
    {
        int p1 = 0,p2 = 0;
        for(int j=1;j<=n;++j)
        {
            if(fabs(c[i][j])>eps) { p1=1; break; }
        }
        if(fabs(b[i])>eps) p2=1;
        rc+=p1;
        rcb+=max(p1,p2);
    }
    if(rc==rcb) ///系数矩阵和增广矩阵的秩相等说明有解
    {
        if(rc<n) return 0;///表示无穷解
        else return 1;///表示唯一解
    }
    else return -1;///秩不等表示无解
}
