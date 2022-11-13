// NTT

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll p=998244353,g=3;
const int N=1<<22;

ll ksm(ll a,ll b){
    if(b==0) return 1;
    ll t=ksm(a,b/2);
    if(b&1) return t*t%p*a%p;
    else return t*t%p;
}
int upp(int u){ int l=1; while(l<u) l<<=1; return l; }

int rev[N];

void NTT(ll a[],int n,int inv){
    n=upp(n);
    for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1) | ((i&1)?(n>>1):0);  
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    ll g0,t;int hl;
    for(int l=2;l<=n;l<<=1){
        g0=ksm(g,(p-1)/l);hl=l>>1;
        for(int i=0;i<n;i+=l){
            t=1;
            for(int j=0;j<hl;j++){
                ll u=a[i+j+hl]*t%p;
                a[i+j+hl]=(a[i+j]-u)%p;
                a[i+j]=(a[i+j]+u)%p;
                t=(t*g0)%p;
            }
        }
    }
    for(int i=0;i<n;i++) (a[i]+=p)%=p;
    if(inv==-1){
        reverse(a+1,a+n);
        ll t=ksm(n,p-2);
        for(int i=0;i<n;i++) a[i]=(a[i]*t)%p;
    }
}

void cpy(ll a[],ll b[],int n){ memcpy(a,b,n*sizeof(ll)); }
void inv(ll a[],ll b[],int n){
    n=upp(n);
    fill(b,b+n+n,0);b[0]=ksm(a[0],p-2);
    static ll r[N];
    for(int t=2;t<=n;t<<=1){
        int t2=t+t;
        copy(a,a+t,r);fill(r+t,r+t2,0);
        NTT(r,t2,1);NTT(b,t2,1);
        for(int j=0;j<t2;j++){ b[j]=(b[j]*(2-r[j]*b[j]%p+p)%p)%p; }
        NTT(b,t2,-1);fill(b+t,b+t2,0);
    }
}
void mod(ll F[],ll G[],ll a[],ll b[],int n,int m){  // F=ag+b, G[m-1]!=0, dest F & G
    reverse(F,F+n);reverse(G,G+m);
    static ll r[N];
    for(int i=n-m+1;i<m;i++) G[i]=0;
    inv(G,r,n-m+1);
    for(int i=n-m+1;i<m;i++) r[i]=0;
    NTT(F,n,1);NTT(r,n,1);
    for(int i=0;i<n;i++) a[i]=F[i]*r[i]%p;
    NTT(a,n,-1);
}

int n,m;
ll F[N],G[N],a[N],b[N];

int main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;n++,m++;
    for(int i=0;i<n;i++) cin>>F[i];
    for(int i=0;i<m;i++) cin>>G[i];

    mod(F,G,a,b,n,m);
    
    for(int i=0;i<upp(n+m);i++) cout<<a[i]<<" "; cout<<"\n";

    return 0;
}