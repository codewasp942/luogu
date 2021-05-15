#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MaxN=100005;

int st[MaxN][20];
int a[MaxN];
int base2[MaxN];
int pw[20];

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void init(int n){
	base2[0]=-1;
	for(int i=1;i<=n;i++){
		base2[i]=base2[i/2]+1;
	}
	pw[0]=1;
	for(int i=1;i<20;i++){
		pw[i]=(pw[i-1]<<1);
	}

	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	}
	for(int k=1;k<=base2[n];k++){
		for(int i=1;i<=n;i++){
			if(i+pw[k-1] > n){
				st[i][k]=-1;
			}else{
				st[i][k]=max(st[i][k-1],st[i+pw[k-1]][k-1]);
			}
		}
	}
}

int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	
	init(n);
	
	int l,r;
	for(int i=1;i<=m;i++){
		l=read();r=read();
		printf("%d\n",max( st[ l ][ base2[r-l+1] ] , st[ r-pw[base2[r-l+1]]+1 ][ base2[r-l+1] ] ));
	}
	return 0;
}