///�������������κδ���1���������ܱ��ֽ�Ϊ���������ĳ˻�
void divide(int n)
{
    int maxm = (int)sqrt(n);
    int p[maxm],c[maxm];
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            p[++m]=i,c[m]=0;
            while(n%i==0) n/=i,++c[m];
        }
    }
    if(n>1) p[++m]=n,c[m]=1; ///˵��n������
    ///�������
    for(int i=1;i<=m;++i)
    {
        printf("%d^%d ",p[i],c[i]);
    }
}

///dfsö������Լ��(�����������ֽ�)
///m��ʾ��ͬ�������ĸ���
int num = 0; ///Լ���ĸ���
void DFS(int x,ll now)
{
    if(x==m+1)
    {
        factor[++num] = now; return;
    }
    for(int i=0;i<=c[x];++i)
    {
        DFS(x+1,now*1LL*(ll)pow(p[x],i));
    }
}
