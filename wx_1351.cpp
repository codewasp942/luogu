#include <iostream>
#include <vector>
#define mod
using namespace std;
const int MaxN=200000;
typedef long long ll;
vector<int> nxt[MaxN];
ll w[MaxN];
ll sm=0,wm=-1;
void dfs(int nw,int fa,int gr){
    if(gr!=-1){
        sm=(sm+(w[nw]%mod*w[gr]%mod*2)%mod)%mod;
        wm=max(wm,w[nw]*w[gr]);
    }
    ll wsm=0,wcm=0;
    ll mx1=-1,mx2=-1;
    for(int i=nxt[nw].size()-1;i>=0;i--){
        int to=nxt[nw][i];
        if(to==fa)continue;
        wsm=(wsm+w[to]%mod)%mod;
        wcm=(wcm+(w[to]%mod)*(w[to]%mod)%mod)%mod;
        if(mx1==-1 || w[to]>=w[mx1]){
            mx2=mx1;mx1=to;
        }else if(mx2==-1 || w[to]>=w[mx2]){
            mx2=to;
        }
        dfs(to,nw,fa);
    }
    sm=(sm+(wsm*wsm)%mod-wcm);
    if((mx1!=-1) && (mx2!=-1)){
        wm=max(wm,w[mx1]*w[mx2]);
    }
}
int main(){
    scanf("%d",&n);
    int frm,to;
    for(int i=1;i<n;i++){
        scanf("%d %d",&frm,&to);
        nxt[frm].push_back(to);
        nxt[to].push_back(frm);
    }

    return 0;
}
