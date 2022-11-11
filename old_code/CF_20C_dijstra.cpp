#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=9E13+9;

struct edge{
	ll w;
	int v;
	edge* nxt;
};

const int MaxN=100005;

edge* e[MaxN]={0};
ll d[MaxN];
int mid[MaxN];
bool vis[MaxN];

void ist(int u,int v,ll w){
	edge* p=new edge;
	p->v=v;
	p->w=w;
	p->nxt=e[u];
	e[u]=p;
}   //juruo999:图的模板

void dijstra(int s,int n){
	priority_queue< pair<ll,int> > q;
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		d[i]=INF;
		mid[i]=-1;
		vis[i]=0;
	}
	d[s]=0;
	mid[s]=1;
	q.push(make_pair(0,1));
	while(!q.empty()){
		ll w=-q.top().first;
		int v=q.top().second;
		q.pop();
		if(vis[v])continue;
		vis[v]=1;
		for(edge* i=e[v];i!=nullptr;i=i->nxt){			
			if(vis[i->v])continue;
			if(d[v]==INF)continue;
			if(d[i->v]>(d[v]+i->w)){
				d[i->v]=(d[v]+i->w);
				mid[i->v]=v;
				q.push(make_pair(-d[i->v],i->v));
			}
		}
	}
}

inline int read() {
    int f=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}

inline void write(int x){
	if(x<0){x=~x+1;putchar('-');}
	if(x>9){write(x / 10);}
	putchar(x%10+'0');
}

inline void outPath(int t){
	if(t==1){
		putchar('1');
		putchar(' ');
		return;
	}
	outPath(mid[t]);
	write(t);
	putchar(' ');
}

int main(){
	int n=read(),m=read();

	int u,v;
	ll w;
	for(int i=0;i<m;i++){
		u=read();
		v=read();
		w=read();
		ist(u,v,w);
		ist(v,u,w);
	}
	
	dijstra(1,n);
	if(d[n]==INF){
    	puts("-1");
	}else{
		outPath(n);
	}
	/*for(int i=1;i<=n;i++){
		printf("%lld ",d[i]);
	}*/
	return 0;
}
