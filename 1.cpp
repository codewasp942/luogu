#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
const int N=500005;

int n,m;
struct Rg{
	int l,r;
	bool operator<(const Rg& o) const { return (r-l)<(o.r-o.l); }
	int len() const { return r-l; }
}a[N];
map<int,int> p;
int tp=0;

namespace Seg{
	// const int M=2000006;
	// int v[M],t[M],ch[M][2],cnt=0;
	// #define ls ch[u][0]
	// #define rs ch[u][1]
	
	// void pushup(int u){ v[u]=max(v[ls],v[rs]); }
	// void apply(int u,int x){ t[u]+=x;v[u]+=x; }
	// void pushdown(int u){
	// 	if(t[u]){
	// 		if(ls) apply(ls,t[u]);
	// 		if(rs) apply(rs,t[u]);
	// 		t[u]=0;
	// 	}
	// }
	
	// int build(int l,int r){
	// 	if(l==r) return ++cnt;
	// 	int mid=(l+r)/2,u=++cnt;
	// 	ls=build(l,mid);
	// 	rs=build(mid+1,r);
	// 	return u;
	// }
	// void add(int u,int l,int r,int L,int R,int x){
	// 	// cout<<u<<" "<<l<<" "<<r<<" | "<<L<<" "<<R<<" "<<x<<endl;
	// 	pushdown(u);
	// 	if(L<=l && r<=R){ apply(u,x);return; }
	// 	int mid=(l+r)/2;
	// 	if(L<=mid) add(ls,l,mid,L,R,x);
	// 	if(R>mid) add(rs,mid+1,r,L,R,x);
	// 	pushup(u);
	// }
	// inline int query(int rt){
	// 	return v[rt];
	// }

	int tree[N*8],add[N*8];
	void Down(int rt,int l,int r){
		if(!add[rt])return;
		int ls=rt*2,rs=rt*2+1;
		tree[ls]+=add[rt];
		tree[rs]+=add[rt];
		add[ls]+=add[rt];
		add[rs]+=add[rt];
		add[rt]=0;
		return;
	}
	void Update(int rt,int l,int r,int x,int y,int val){
		cout<<l<<" "<<r<<endl;
		if(x>r||y<l)return;
		if(x<=l&&y>=r){
			tree[rt]+=val;
			add[rt]+=val;
			return;
		}
		int mid=(l+r)/2;
		Down(rt,l,r);
		Update(rt*2,l,mid,x,y,val);
		Update(rt*2+1,mid+1,r,x,y,val);
		tree[rt]=max(tree[rt*2],tree[rt*2+1]);
		return;
	}
}
using namespace Seg;

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		p[a[i].l]=p[a[i].r]=1;
	}
	for(auto& i:p){ i.second=++tp; }
	for(int i=1;i<=n;i++) a[i].l=p[a[i].l],a[i].r=p[a[i].r];
	
	sort(a+1,a+n+1);

	int rt=1,l=0,r=0,ans=1145141919;	// (l,r]
	while(1){
		while(tree[rt]<m && r<=n){ r++; cout<<r<<endl; Update(rt,1,tp,a[r].l,a[r].r,1); }
		if(tree[rt]<m) break;
		while(tree[rt]>=m && l<=n){ l++; cout<<l<<endl; Update(rt,1,tp,a[l].l,a[l].r,-1); }
		ans=min(ans,a[r].len()-a[l].len());
	}
	cout<<((ans!=1145141919)?ans:(-1))<<"\n";
	
	return 0;
}