#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MaxN=500005;

struct edge{
	int v;
	edge* nxt;
};
edge* E[MaxN]={0};
int father[MaxN],deepth[MaxN];
int up[MaxN][35];

void ist(int u,int v){
	edge* p=new edge;
	p->v=v;
	p->nxt=E[u];
	E[u]=p;
}   //juruo999:图的模板

void dfs(int nw,int fa,int dep){
	father[nw]=fa;
	deepth[nw]=dep;
	for(edge* i=E[nw];i!=NULL;i=i->nxt){
		if(i->v==fa)continue;
		dfs(i->v,nw,dep+1);
	}
}

void init(int n,int s){
	dfs(s,0,1);
	int dep;
	for(int i=1;i<=n;i++){
		up[i][0]=father[i];
	}
	for(int k=1;k<=30;k++){
		for(int i=1;i<=n;i++){
			up[i][k]=up[up[i][k-1]][k-1];
		}
	}
}

int lca(int u,int v){
	if(u==v){
		return u;
	}
	if(deepth[v]>deepth[u]){
		swap(u,v);
	}
	for(int k=30;k>=0;k--){
		if(deepth[up[u][k]]>=deepth[v]){
			u=up[u][k];
		}
	}
	for(int k=30;k>=0;k--){
		if(up[u][k]!=up[v][k]){
			u=up[u][k];
			v=up[v][k];
		}
	}
	if(u==v){
		return u;
	}
	return up[u][0];
}

int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		register int x,y;
		scanf("%d%d",&x,&y);
		ist(x,y);
		ist(y,x);
	}
	dfs(s,0,0);
	init(n,s);
	for(int i=1;i<=m;i++){
		register int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}