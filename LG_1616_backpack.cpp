#include<cstdio>
using namespace std;
int v[10004],w[10004];
long long dp[10000007];
int main(){
	int m,t;
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&v[i],&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t;j++){
			if(j>=v[i] && dp[j-v[i]]+w[i] > dp[j]){
				dp[j]=dp[j-v[i]]+w[i];
			}
		}
	}
	printf("%lld",dp[t]);
	return 0;
}