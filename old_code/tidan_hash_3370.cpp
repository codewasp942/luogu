#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const ull mod=524343;

ull calHash(char* s,ull m,int l);

struct hashRes{
    ull h1,h2;
}h[10004];

bool cmp(hashRes a,hashRes b){
    return make_pair(a.h1,a.h2)<make_pair(b.h1,b.h2);
}

int main() {
    int n;
    scanf("%d",&n);
    char str[1503];
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        h[i].h1=calHash(str,1E9+7,strlen(str));
        h[i].h2=calHash(str,1E9+9,strlen(str));
    }
    sort(h+1,h+n+1,cmp);
    int cnt=1;
    for(int i=2;i<=n;i++){
        if((h[i].h1!=h[i-1].h1)&&(h[i].h2!=h[i-1].h2)){
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}

ull calHash(char* s,ull m,int l){
    ull v=0;
    for(int i=0;i<l;i++){
        v=((v*131)%m+ull(s[i]))%m;
    }
    return v;
}
