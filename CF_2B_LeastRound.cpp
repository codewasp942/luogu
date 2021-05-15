#include <iostream>
#include <cstdio>
using namespace std;
int a[1003][1003],t[2][1003][1003],dp[2][2][1003][1003];
bool h[1003][1003];
void outPath(int x,int y){
	int k=0;
	if(dp[0][0][x][y]>dp[1][0][x][y]){
		k=1;
	}
	//printf("%d %d\n",x,y);
	if(x<=1 && y<=1){
		return;
	}else if(dp[k][1][x][y]==0){
		outPath(x-1,y);
		putchar('D');
	}else if(dp[k][1][x][y]==1){
		outPath(x,y-1);
		putchar('R');
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int tmp;
	bool flg=0;
	int x0,y0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0){
				flg=1;
				x0=i;y0=j;
			}
			tmp=a[i][j];
			t[0][i][j]=t[1][i][j]=0;
			while((tmp>0) && (tmp%2==0)){
				t[0][i][j]++;
				tmp/=2;
			}
			tmp=a[i][j];
			t[1][i][j]=0;
			while((tmp>0) && (tmp%5==0)){
				t[1][i][j]++;
				tmp/=5;
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[0][0][i][j]=dp[1][0][i][j]=INT_MAX;
			dp[0][1][i][j]=dp[1][1][i][j]=-1;
		}
	}
	dp[0][0][1][1]=t[0][1][1];
	dp[1][0][1][1]=t[1][1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j && j==1){
				continue;
			}
			for(int k=0;k<=1;k++){
				if(dp[k][0][i-1][j]<dp[k][0][i][j-1]){
					dp[k][0][i][j]=dp[k][0][i-1][j];
					dp[k][1][i][j]=0;
				}else{
					dp[k][0][i][j]=dp[k][0][i][j-1];
					dp[k][1][i][j]=1;
				}
				dp[k][0][i][j]+=t[k][i][j];
			}
		}
	}
	printf("%d\n",min(min(dp[0][0][n][n],dp[0][1][n][n]),1));
	if(flg && (min(dp[0][0][n][n],dp[0][1][n][n])>=1)){
		for(int i=2;i<=x0;i++){
			putchar('D');
		}
		for(int i=2;i<=y0;i++){
			putchar('R');
		}
		for(int i=x0+1;i<=n;i++){
			putchar('D');
		}
		for(int i=y0+1;i<=n;i++){
			putchar('R');
		}
	}else{
		outPath(n,n);
	}
	return 0;
}
