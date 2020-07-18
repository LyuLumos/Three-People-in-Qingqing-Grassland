#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define show(x) std::cerr << #x << "=" << x << std::endl
using namespace std;
typedef long long ll;
const double eps=1e-8;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int t;
int n,m;
///BST建立
struct BST{
    int l,r; ///左右子节点的下标
    int val;///节点关键码
} a[maxn];
int tot,root;///节点数，根节点
int New(int val)
{
    a[++tot].val = val; return tot;
}
void Build()
{
    New(-inf),New(inf);
    root = 1,a[1].r = 2;  ///负无穷为根节点(1)，正无穷为其右节点(2)
}
///BST检索  查找是否存在关键码为val的节点下标
int Get(int p,int val)
{
    if(p==0) return 0; ///检索失败
    if(a[p].val==val) return p;///检索成功，返回节点编号
    return a[p].val<val?Get(a[p].l,val):Get(a[p].r,val);
}
///BST插入 插入新值val
void Insert(int &p,int val)
{
    if(p==0)
    {
        p = New(val); return;
    }
    if(val==a[p].val) return;
    val<a[p].val?Insert(a[p].l,val):Insert(a[p].r,val);
}
///BST求后继  求大于val的最小的节点下标
int Getnext(int val)
{
    int ans = 2; int p = root;
    while(p){
        if(val == a[p].val){
            if(a[p].r>0){
                p = a[p].r;
                while(a[p].l>0) p = a[p].l;
                ans = p;
            }
            break;
        }
        if(a[p].val>val && a[p].val<a[ans].val) ans = p;
        p = val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
///BST求前驱 求小于val的最大的节点下标
int Getpre(int val)
{
    int ans = 1; int p = root;
    while(p){
        if(val == a[p].val){
            if(a[p].l>0){
                p = a[p].l;
                while(a[p].r>0) p = a[p].r;
                ans = p;
            }
            break;
        }
        if(a[p].val<val && a[p].val>a[ans].val) ans = p;
        p = val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
///BST节点删除  删除关键码为val的节点
void Remove(int &p,int val)
{
    if(p==0) return;
    if(val==a[p].val) {
        if(a[p].l==0){
            p = a[p].r;
        }
        else if(a[p].r==0){
            p = a[p].l;
        }
        else
        {
            int next  = a[p].r;
            while(a[next].l>0) next = a[next].l;
            Remove(a[p].r,a[next].val);
            a[next].l=a[p].l,a[next].r=a[p].r;
            p = next;
        }
        return ;
    }
    if(val<a[p].val){
        Remove(a[p].l,val);
    }else{
        Remove(a[p].r,val);
    }
}
///左右旋转
///右旋
void zig(int &p)
{
    int q = a[p].l;
    a[p].l = a[q].r, a[q].r = p;
    p = q;
}
///左旋
void zag(int &p)
{
    int q = a[p].r;
    a[p].r = a[q].l, a[q].l = p;
    p = q;
}
int main()
{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return 0;
}
