#include <iostream>
#include <cstdio>
using namespace std;

int s[10000007];

inline int lowbit(int x);
inline int getsum(int* SumMem,int x);
inline int getsum(int* SumMem,int x,int y);
inline void addval(int *SumMem,int x,int v,int n);

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int x,a,b;
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(x==0){
			scanf("%d%d",&a,&b);
			addval(s,a,1,n);
			if(b<n){
				addval(s,b+1,-1,n);
			}
		}else{
			scanf("%d",&a);
			printf("%d\n",getsum(s,a));
		}
	}
	return 0;
}

inline int lowbit(int x){
	return x&(-x);
}

inline int getsum(int* SumMem,int x){
	int sum=0;
	for(int i=x;i;i-=lowbit(i)){
		sum+=SumMem[i];
	}
	return sum;
}

inline int getsum(int* SumMem,int x,int y){
	return getsum(SumMem,y)-getsum(SumMem,x-1);
}

inline void addval(int *SumMem,int x,int v,int n){
	for(int i=x;i<=n;i+=lowbit(i)){
		SumMem[i]+=v;
	}
}
