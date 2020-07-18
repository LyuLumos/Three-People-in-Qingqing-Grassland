#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int DEG = 21;
int f[maxn][DEG];
int deg[maxn];

struct edge {
	int nxt,v;
} e[2*maxn];
int head[maxn];
int cnt = 0;
void add_e(int u,int v) {
	e[cnt].nxt = head[u];
	e[cnt].v = v;
	head[u] = cnt++;
}

void init() {
	cnt =  0;
	memset(head,-1,sizeof head);
	memset(deg,0,sizeof deg);
	memset(f,0,sizeof f);
}

void bfs(int root) {
	queue<int>q;
	q.push(root);
	deg[root] = 0;
	f[root][0] = root;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=1; i<DEG; ++i) f[u][i] = f[f[u][i-1]][i-1];
		for(int i=head[u]; ~i; i=e[i].nxt) {
			int v = e[i].v;
			if(v==f[u][0]) continue;
			deg[v] = deg[u] + 1;
			f[v][0] = u;
			q.push(v);
		}
	}
}
int LCA(int u,int v) {
	if(deg[u]>deg[v]) swap(u,v);
	int hu = deg[u],hv = deg[v];
	int tu = u, tv = v;
	for(int det = hv-hu,i=0; det; det>>=1,++i) {
		if(det&1) tv = f[tv][i];
	}
	if(tu == tv) return tu;
	for(int i=DEG-1; i>=0; --i) {
		if(f[tu][i] == f[tv][i]) continue;
		tu = f[tu][i];
		tv = f[tv][i];
	}
	return f[tu][0];
}
int main() {
	int t;
	scanf("%d",&t);
	int n,m,q,v;
	for(int i=1; i<=t; ++i) {
		init();
		scanf("%d",&n);
		for(int u=1; u<=n; ++u) {
			scanf("%d",&m);
			while(m--) {
				scanf("%d",&v);
				add_e(u,v);
				add_e(v,u);
			}
		}
		bfs(1);
		scanf("%d",&q);
		int a,b;
		printf("Case %d:\n",i);
		for(int i=0; i<q; ++i) {
			scanf("%d%d",&a,&b);
			printf("%d\n",LCA(a,b));
		}
	}
}
