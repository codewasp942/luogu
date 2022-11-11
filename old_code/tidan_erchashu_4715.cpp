#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[130];
    bool b[130];
    for(int i=1;i<=(1<<n);i++){
        cin>>a[i];
        b[i]=1;
    }
    for(int i=1;i<n;i++){
        int lf1=-1;bool f=0;
        for(int j=1;j<=(1<<n);j++){
            if(b[j]){
                f=!f;
                if(f==0){
                    if(lf1!=-1){
                        if(a[j]>a[lf1]){
                            b[lf1]=0;
                        }else{
                            b[j]=0;
                        }
                    }
                }else{
                    lf1=j;
                }
            }
        }
    }
    int v1=-1,v2=-1;
    for(int i=1;i<=(1<<n);i++){
        if(b[i]==1){
            if(v1==-1){
                v1=i;
            }else if(v2==-1){
                v2=i;
            }
        }
    }
    if(a[v1]<a[v2]){
        cout<<v1;
    }else{
        cout<<v2;
    }
    return 0;
}
