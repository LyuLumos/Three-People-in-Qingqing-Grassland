int a[maxn],c[maxn]; ///a[i]��¼����ֵ��c[i]��¼[i-lowbit(i)+1,i]���������ĺ�

int ask(int x)  ///��ѯ1~x��ǰ׺�� O(logn)
{
    int ans = 0;
    for(;x;x-=(x&-x)) ans+=c[x];
    return ans;
}
void add(int x,int y) ///��������a[x]+y O(logn)
{
    for(;x<=n;x+=(x&-x)) c[x]+=y;
}
int query(int k)  ///O(logn)��ѯ��kС
{
    int ans=0,sum=0;
    for(int i=20;i>=0;--i)
    {
        if(ans+(1<<i)<=n && sum+c[ans+(1<<i)]<k)
        {
            sum+=c[ans+(1<<i)];
            ans+=(1<<i);
        }
    }
    return ans+1;
}
void init(int n) ///��ʼ����״���� O(nlogn)
{
    for(int i=1;i<=n;++i) c[i] = 0;
    for(int i=1;i<=n;++i) add(i,a[i]);
}

int fun()  ///��������� O((n+m)logm)  ,c[i] ��ʾ��Χ��[1,i]�ڵ�������
{
    ///�ر�Ҫע��c����ĳ�ʼ����Χ��addʱ����ֹ����
    for(int i=n;i>=1;--i)
    {
        ans+=ask(a[i]-1);  ///�ۼ�i+1~n��С��a[i]�ĸ���
        add(a[i],1);
    }
    return ans;
}
