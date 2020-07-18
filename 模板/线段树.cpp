struct ST{ ///�߶����ṹ�嶨��
    int l,r;
    int dat;
}t[4*maxn];

void build(int p,int l,int r) ///����
{
    t[p].l = l,t[p].r = r;
    if(l==r) {t[p].dat=a[l];return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}
void change(int p,int x,int v)  ///�����޸� a[x]->v;
{
    if(t[p].l==t[p].r) {t[p].dat=v;return;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p*2,x,v);
    else change(p*2+1,x,v);
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}
int ask(int p,int l,int r)  ///�����ѯ
{
    if(l<=t[p].l && t[p].r<=r) return t[p].dat;
    int mid = (t[p].l+t[p].r)/2;
    int val = -inf;
    if(l<=mid) val = max(val,ask(p*2,l,r));
    if(r>mid) val = max(val,ask(p*2+1,l,r));
    return val;
}


///***************************************
///ע��
struct ST
{
    int l,r;
    int dat;
}t[maxn*4];
void build(int p,int l,int r) ///���� ���Σ���ţ���˵㣬�Ҷ˵�
{
    t[p].l=l,t[p].r=r;
    if(l==r) {t[p].dat=a[l];return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}
///������ڣ�  build(1,1,n)  �ӱ��Ϊ1��ʼ����ά��[1,n]��Ϣ���߶���

void change(int p,int x,int v)///�����޸�  a[x]->v �������ϸ���
{
    if(t[p].l == t[p].r){t[p].dat = v;return;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p*2,x,v);  ///�ݹ�������
    else change(p*2+1,x,v);      ///�ݹ�������
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat); ///�������ϸ���
}
///������ڣ�  change(1,x,v)  �Ӹ��ڵ�����ҵ���ӦҶ�ڵ�(��������[x,x])Ȼ��������ϸ���

int ask(int p,int l,int r)///�����ѯ
{
    if(l<=t[p].l && r>=t[p].r) return t[p].dat;  ///[l,r]����[t[p].l,t[p].r]��ֱ�ӷ�����Ϊ��ѡ��
    int mid = (t[p].l+t[p].r)/2;
    int val = -(1<<30); ///��ʼΪ������
    if(l<=mid) val=max(val,ask(p*2,l,r)); ///���������ص� �ݹ�������
    if(r>mid) val=max(val,ask(p*2+1,l,r));///���������ص� �ݹ�������
    return val;
}
///������ڣ�  ask(1,l,r) �Ӹ��ڵ������ѯ[l,r]�ϵ���Ϣ
