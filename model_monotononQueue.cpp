#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;

struct node{
	int pos,val;
};

const int MaxN=1000006;
int a[MaxN];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	deque<node> q;			//单调队列
	while(!q.empty()){q.pop_back();}
	for(int i=1;i<=m;i++){
		while(!q.empty() && q.back().val>=a[i]){
			q.pop_back();
		}
		node nd;
		nd.pos=i;
		nd.val=a[i];
		q.push_back(nd);
	}
	printf("%d\n",q.front().val);
	for(int i=m+1;i<=n;i++){
		while(!q.empty() && q.back().val>=a[i]){
			q.pop_back();
		}
		while(!q.empty() && q.front().pos<(i-m+1)){
			q.pop_front();
		}
		node nd;
		nd.pos=i;
		nd.val=a[i];
		q.push_back(nd);
		printf("%d\n",q.front().val);
	}
	return 0;
}