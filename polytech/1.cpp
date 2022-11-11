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

int rev[N];

void NTT(ll a[],int n,int inv){
    for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1) | ((i&1)?(n>>1):0);
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    ll g0,t;int hl;
    for(int l=2;l<=n;l<<=1){
        g0=ksm(g,(p-1)/l);hl=l<<1;
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
    if(inv==-1){
        reverse(a+1,a+n);
        ll t=ksm(n,p-2);
        cout<<t<<"\n";
        for(int i=0;i<n;i++) a[i]=(a[i]*t)%p;
    }
}

int n,m;
ll a[N],b[N];
int L;

int main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;n++,m++;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    for(L=1;L<n+m;L<<=1);

    NTT(a,L,1);
    NTT(b,L,1);
    for(int i=0;i<L;i++) a[i]=(a[i]*b[i])%p;
    NTT(a,L,-1);

    for(int i=0;i<n+m;i++) cout<<a[i]<<" ";
    cout<<"\n";

    return 0;
}