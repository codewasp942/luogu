#include <iostream>
#include <cstdio>
using namespace std;
int a[1003][1003];
int main(){
    int n,m;
    int x1,y1,x2,y2;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2){swap(x1,x2);}
        if(y1>y2){swap(y1,y2);}
        for(int j=x1;j<=x2;j++){
            a[j][y1]++;
            a[j][y2+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=a[i][j];
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}
