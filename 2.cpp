#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
const int maxn=501000;
const int INF=1e9;
struct Point{
    int val,ord;
}p[maxn*4];
struct Data{
    int len,ord;
}a[maxn*4];
int L[maxn*2],R[maxn*2],n,m,Right,cur=0;
int tree[maxn*8],add[maxn*8];
bool Cmp1(Point x1,Point x2){
    if(x1.val<x2.val)return true;
    return false;
}
bool Cmp2(Data x1,Data x2){
    if(x1.len<x2.len)return true;
    return false;
}
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
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        a[i].len=v-u;
        a[i].ord=i;
        cur++;
        p[cur].val=u;
        p[cur].ord=i;
        cur++;
        p[cur].val=v;
        p[cur].ord=i;
    }
    sort(p+1,p+cur+1,Cmp1);
    int num=0;
    p[0].val=-1;
    for(int i=1;i<=cur;i++){
        if(p[i].val!=p[i-1].val)
        num++;
        int u=p[i].ord;
        if(!L[u])
        L[u]=num;
        else R[u]=num;
    }
    Right=num;
    sort(a+1,a+n+1,Cmp2);
    int ans=INF,le=0,ri=0;
    while(true){
        while(tree[1]<m&&ri<=n){
            ri++;
            int u=a[ri].ord,v=L[u],w=R[u];
            Update(1,1,Right,v,w,1);
        }
        if(tree[1]<m)break;
        while(tree[1]>=m&&le<=n){
            le++;
            int u=a[le].ord,v=L[u],w=R[u];
            Update(1,1,Right,v,w,-1);
        }
        ans=min(ans,a[ri].len-a[le].len);
    }
    if(ans==INF)printf("-1\n");
    else
    printf("%d\n",ans);
    return 0;
}