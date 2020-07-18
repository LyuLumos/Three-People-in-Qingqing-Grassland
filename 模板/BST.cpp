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
///BST����
struct BST{
    int l,r; ///�����ӽڵ���±�
    int val;///�ڵ�ؼ���
} a[maxn];
int tot,root;///�ڵ��������ڵ�
int New(int val)
{
    a[++tot].val = val; return tot;
}
void Build()
{
    New(-inf),New(inf);
    root = 1,a[1].r = 2;  ///������Ϊ���ڵ�(1)��������Ϊ���ҽڵ�(2)
}
///BST����  �����Ƿ���ڹؼ���Ϊval�Ľڵ��±�
int Get(int p,int val)
{
    if(p==0) return 0; ///����ʧ��
    if(a[p].val==val) return p;///�����ɹ������ؽڵ���
    return a[p].val<val?Get(a[p].l,val):Get(a[p].r,val);
}
///BST���� ������ֵval
void Insert(int &p,int val)
{
    if(p==0)
    {
        p = New(val); return;
    }
    if(val==a[p].val) return;
    val<a[p].val?Insert(a[p].l,val):Insert(a[p].r,val);
}
///BST����  �����val����С�Ľڵ��±�
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
///BST��ǰ�� ��С��val�����Ľڵ��±�
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
///BST�ڵ�ɾ��  ɾ���ؼ���Ϊval�Ľڵ�
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
///������ת
///����
void zig(int &p)
{
    int q = a[p].l;
    a[p].l = a[q].r, a[q].r = p;
    p = q;
}
///����
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
