#include <iostream>
#include <cstdio>
using namespace std;
const int MaxN=200005;
int a[MaxN],dp[MaxN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=a[i];
    }
    int res=dp[1];
    for(int i=2;i<=n;i++){
        if(dp[i-1]>0){
            dp[i]=a[i]+dp[i-1];
        }else{
            dp[i]=a[i];
        }
        res=max(res,dp[i]);
    }
    printf("%d",res);
    return 0;
}
