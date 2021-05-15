#include <iostream>
#include <math.h>
#include <cstring>
#define maxs(x,y) ((x>y)?(x):(y))
using namespace std;
typedef __int128 val;
val a[82][82];
val f[82][82];
val ans=0;
inline __int128 getint128(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void outuint128(__int128 x){
    if(x==0)return;
    outuint128(x/10);
    putchar(x%10+'0');
}
val mpow(val x,val y){ //�����ÿ�����
    val a=1;
    for(val i=1;i<=y;i++){
        a*=x;
    }
    return a;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=getint128();
            //outuint128(a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        val mx=-1000;
        for(int j=1;j<=m;j++){
            for(int k=m;k>=j;k--){ //���м�ƽ�
                int l=k-j+1;
                f[j][k]=maxs(maxs(val(f[j][k]),val(f[j-1][k]+a[i][j-1]*mpow(2,m-l))),val(f[j][k+1]+a[i][k+1]*mpow(2,m-l)));
            }
            f[j][j]+=pow(2,m)*a[i][j];
        }
        for(int j=1;j<=m;j++){
            mx=maxs(mx,f[j][j]);
        }
        ans+=mx;
    }
    if(ans==0)cout<<0;else outuint128(ans);
    return 0;
}
