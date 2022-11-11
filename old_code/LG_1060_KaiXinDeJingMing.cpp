#include<cstdio>
using namespace std;
int v[30],w[30];
int dp[30004];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&v[i],&w[i]);
		w[i]*=v[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=0;j--){
			if(j>=v[i] && (dp[j-v[i]]+w[i])>dp[j]){
				dp[j]=(dp[j-v[i]]+w[i]);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}