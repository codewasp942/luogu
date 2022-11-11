#include<iostream>
#include<cstdio>
using namespace std;

void setup(int *fat,int n);
int getfa(int *fat,int u);
void merge(int *fat,int u,int v);
bool query(int *fat,int u,int v);

int main() {
    int fa[10009];
    int n,m;
    while(1){
        scanf("%d",&n);
        if(n==0){break;}
        scanf("%d",&m);
        setup(fa,n);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            merge(fa,x,y);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(getfa(fa,i)==i){
                cnt++;
            }
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}

void setup(int *fat,int n){
    for(int i=1;i<=n;i++){
        fat[i]=i;
    }
}

int getfa(int *fat,int u){
    return (fat[u]==u)?(u):(fat[u]=getfa(fat,fat[u]));
}

void merge(int *fat,int u,int v){
    fat[getfa(fat,u)]=getfa(fat,v);
}

bool query(int *fat,int u,int v){
    return getfa(fat,u)==getfa(fat,v);
}
