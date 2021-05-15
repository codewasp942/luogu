#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

struct edge{
	int v;
	edge* nxt;
};

const int MaxN=100005;

int father[MaxN],deepth[MaxN];
int up[MaxN][35];
char s[MaxN],out[100005];
int v[MaxN];
edge* E[MaxN]={0};

void ist(int u,int v){
	edge* p=new edge;
	p->v=v;
	p->nxt=E[u];
	E[u]=p;
}   //juruo999:图的模板

void dfs(int nw,int fa,int dep){
	father[nw]=fa;
	deepth[nw]=dep;
	v[nw]+=v[fa];
	for(edge* i=E[nw];i!=NULL;i=i->nxt){
		if(i->v==fa)continue;
		dfs(i->v,nw,dep+1);
	}
}

void init(int n){
	dfs(1,0,1);
	int dep;
	for(int i=1;i<=n;i++){
		up[i][0]=father[i];
	}
	for(int k=1;k<=30;k++){
		for(int i=1;i<=n;i++){
			dep=(1<<k);
			if(deepth[i]>dep){
				up[i][k]=up[up[i][k-1]][k-1];
			}
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
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='G'){
			v[i+1]=0;
		}else{
			v[i+1]=1;
		}
	}
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		ist(x,y);
		ist(y,x);
	}
	init(n);
	char op;
	for(int i=1;i<=m;i++){
		scanf("%d %d %c",&x,&y,&op);
		int zx=lca(x,y);
		int len=deepth[x]+deepth[y]-2*deepth[zx]+1;
		int sm=v[x]+v[y]-v[zx]-v[father[zx]];
		if(op=='H'){
			if(sm!=0){
				out[i-1]='1';
			}else{
				out[i-1]='0';
			}
		}else{
			if(sm!=len){
				out[i-1]='1';
			}else{
				out[i-1]='0';
			}
		}
	}
	out[m]='\0';
	printf("%s",out);
	return 0;
}