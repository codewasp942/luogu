#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

ll m[100005];

int lowbit(int x){
	return x&(-x);
}

void add(int a,ll b,int n){
	for(int i=a;i<=n;i+=lowbit(i)){
		m[i]+=b;
	}
}

ll query(int a){
	ll sum=0;
	for(int i=a;i>=1;i-=lowbit(i)){
		sum+=m[i];
	}
	return sum;
}

int main(){
	int n,w;
	scanf("%d%d",&n,&w);

	char op;
	int a,b;
	for(int i=1;i<=w;i++){

		cin>>op>>a>>b;
		if(op=='x'){
			add(a,b,n);
		}else{
			printf("%lld\n",query(b)-query(a-1));
		}
	}
	return 0;
}