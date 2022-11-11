#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

typedef long long ll;
int dp[12][1000][90];

void outbin(ll x,int s){
	stack<char> S;
	while(!S.empty()){
		S.pop();
	}
	while(x){
		if(x&1)	S.push('#');
		else	S.push('.');
		x>>=1;
	}
	putchar('|');
	for(int i=1;i<=s-S.size();i++){
		putchar('.');
	}
	while(!S.empty()){
		putchar(S.top());
		S.pop();
	}
	putchar('|');
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<(1<<n);j++){
			for(int k=0;k<=m;k++){
				if(k==0){
					dp[i][j][k]=1;
				}else{
					dp[i][j][k]=0;
				}
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		if(i|(i<<1)){
			
		}
	}
	return 0;
}