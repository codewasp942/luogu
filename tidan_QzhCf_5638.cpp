#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
ll a[1000006],x[1000006];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%lld",&x[i]);
    }
    a[1]=0;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+x[i-1];
    }
    ll res=LLONG_MIN;
    for(int i=k+1;i<=n;i++){
        res=max(res,a[i]-a[i-k]);
    }
    printf("%lld",a[n]-res);
    return 0;
}
