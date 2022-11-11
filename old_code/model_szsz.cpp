#include <iostream>
using namespace std;

int s[1009];

inline int lowbit(int x);
inline int getsum(int* SumMem,int x);
inline int getsum(int* SumMem,int x,int y);
inline void addval(int *SumMem,int x,int v,int n);

int main(){
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        addval(s,i,x,n);
    }
    int q;
    cin>>q;
    string op;int a,b;
    for(int i=1;i<=q;i++){
        cin>>op>>a>>b;
        if(op=="query"){
            cout<<getsum(s,a,b)<<endl;
        }else{
            addval(s,a,b,n);
        }
    }
    return 0;
}

inline int lowbit(int x){
    return x&(-x);
}

inline int getsum(int* SumMem,int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=SumMem[i];
    }
    return sum;
}

inline int getsum(int* SumMem,int x,int y){
    return getsum(SumMem,y)-getsum(SumMem,x-1);
}

inline void addval(int *SumMem,int x,int v,int n){
    for(int i=x;i<=n;i+=lowbit(i)){
        SumMem[i]+=v;
    }
}
