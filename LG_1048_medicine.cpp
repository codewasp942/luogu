#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int v[105],w[105];
int dp[1005];
int main(){
	int t,m;
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&v[i],&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=t;j>=1;j--){
			if(j>=v[i]){
				dp[j]=max(dp[j-v[i]]+w[i],dp[j]);
			}
		}
	}
	printf("%d",dp[t]);
}