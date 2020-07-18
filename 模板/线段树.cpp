struct ST{ ///线段树结构体定义
    int l,r;
    int dat;
}t[4*maxn];

void build(int p,int l,int r) ///建树
{
    t[p].l = l,t[p].r = r;
    if(l==r) {t[p].dat=a[l];return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}
void change(int p,int x,int v)  ///单点修改 a[x]->v;
{
    if(t[p].l==t[p].r) {t[p].dat=v;return;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p*2,x,v);
    else change(p*2+1,x,v);
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}
int ask(int p,int l,int r)  ///区间查询
{
    if(l<=t[p].l && t[p].r<=r) return t[p].dat;
    int mid = (t[p].l+t[p].r)/2;
    int val = -inf;
    if(l<=mid) val = max(val,ask(p*2,l,r));
    if(r>mid) val = max(val,ask(p*2+1,l,r));
    return val;
}


///***************************************
///注释
struct ST
{
    int l,r;
    int dat;
}t[maxn*4];
void build(int p,int l,int r) ///建树 传参：编号，左端点，右端点
{
    t[p].l=l,t[p].r=r;
    if(l==r) {t[p].dat=a[l];return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat);
}
///调用入口：  build(1,1,n)  从编号为1开始建立维护[1,n]信息的线段树

void change(int p,int x,int v)///单点修改  a[x]->v 从下往上更新
{
    if(t[p].l == t[p].r){t[p].dat = v;return;}
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid) change(p*2,x,v);  ///递归左子树
    else change(p*2+1,x,v);      ///递归右子树
    t[p].dat = max(t[p*2].dat,t[p*2+1].dat); ///从下往上更新
}
///调用入口：  change(1,x,v)  从根节点出发找到对应叶节点(代表区间[x,x])然后从下往上更新

int ask(int p,int l,int r)///区间查询
{
    if(l<=t[p].l && r>=t[p].r) return t[p].dat;  ///[l,r]包含[t[p].l,t[p].r]则直接返回作为备选答案
    int mid = (t[p].l+t[p].r)/2;
    int val = -(1<<30); ///初始为负无穷
    if(l<=mid) val=max(val,ask(p*2,l,r)); ///左子树有重叠 递归左子树
    if(r>mid) val=max(val,ask(p*2+1,l,r));///右子树有重叠 递归右子树
    return val;
}
///调用入口：  ask(1,l,r) 从根节点出发查询[l,r]上的信息
