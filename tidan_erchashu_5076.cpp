#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[10009];
int main(){
    int q,n=0;
    scanf("%d",&q);
    int op,val;
    while(q--){
        scanf("%d%d",&op,&val);
        if(op==5){
            n++;
            a[n]=val;
            for(int i=n-1;i>=1;i--){
                if(a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
                }else{
                    break;
                }
            }
        }else if(op==1){
            int idx=lower_bound(a+1,a+n+1,val)-a;
            printf("%d\n",idx);
        }else if(op==2){
            printf("%d\n",a[val]);
        }else if(op==3){
            int idx=lower_bound(a+1,a+n+1,val)-a;
            if(val<a[1]){
                printf("-2147483647\n");
            }else{
                printf("%d\n",a[idx-1]);
            }
        }else if(op==4){
            int idx=upper_bound(a+1,a+n+1,val)-a;
            if(val>a[n]){
                printf("2147483647\n");
            }else{
                printf("%d\n",a[idx]);
            }
        }
    }
    return 0;
}
