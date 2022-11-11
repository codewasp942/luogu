#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int a[1003][1003],b[1003][1003];
int main(){
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    int res=INT_MIN;
    int resx,resy;
    for(int i=c;i<=n;i++){
        for(int j=c;j<=m;j++){
            int nw=b[i][j]-b[i-c][j]-b[i][j-c]+b[i-c][j-c];
            if(nw>=res){
                res=nw;
                resx=i-c+1;
                resy=j-c+1;
            }
        }
    }
    printf("%d %d",resx,resy);
    return 0;
}
