#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int a[1003][1003],b[1003][1003];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    int res=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    int nw=b[i][j]-b[k-1][j]-b[i][l-1]+b[k-1][l-1];
                    res=max(res,nw);
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}
