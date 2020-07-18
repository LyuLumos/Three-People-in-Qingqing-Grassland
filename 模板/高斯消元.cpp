int Gauss(double c[][N],double b[N])
{
    int rc=0,rcb=0;///��ʼ����Ϊ0
    ///��˹��Ԫ����
    ///c�����ʾϵ������b�����ʾ��������
    for(int i=1;i<=n;++i)
    {
        ///�ҵ�һ��x[i]��ϵ�����Ȼ����һ�����i�л���
        ///��Ϊǰi-1���Ѿ�����������Դӵ�i�п�ʼ������
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
        ///����i�г���i�����������ϵ��ȫ��Ϊ0
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
    if(rc==rcb) ///ϵ��������������������˵���н�
    {
        if(rc<n) return 0;///��ʾ�����
        else return 1;///��ʾΨһ��
    }
    else return -1;///�Ȳ��ȱ�ʾ�޽�
}
