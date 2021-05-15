#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll x[100005],a[100005],b[100005],c[100005];
int p[100005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    for(int i=2;i<=m;i++){
        int f=p[i-1],t=p[i];
        if(f>t){swap(f,t);}
        x[f]++;
        x[t]--;
    }
    ll sum=0,res=0;
    for(int i=1;i<n;i++){
        sum+=x[i];
        res+=min(a[i]*sum,c[i]+b[i]*sum);
    }
    printf("%lld",res);
    return 0;
}
