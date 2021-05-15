#include <iostream>
using namespace std;
int l[1000009],r[1000009];
int dfs(int nw){
    if((l[nw]==0) && (r[nw]==0))return 1;
    return max(dfs(l[nw]),dfs(r[nw]))+1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    cout<<dfs(1);
    return 0;
}
