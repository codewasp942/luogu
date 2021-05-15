#include <iostream>
#include <cstdio>
using namespace std;
const int mod=10007,MaxN=100005,MaxM=100005;
int cnt[MaxM][2],sum[MaxM][2];
int num[MaxN],col[MaxN];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&col[i]);
    }
    for(int i=1;i<=n;i++){
        cnt[col[i]][i%2]++;
        sum[col[i]][i%2]=( sum[col[i]][i%2]%mod + num[i]%mod )%mod;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res=( res%mod + ( i * ( (cnt[col[i]][i%2]-2) * num[i]%mod + sum[col[i]][i%2])%mod )%mod )%mod;
    }
    printf("%d",res);
    return 0;
}
