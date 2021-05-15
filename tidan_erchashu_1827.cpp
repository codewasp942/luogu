#include<string>
#include<iostream>
using namespace std;
string sol(string a,string b,int l,int r,int l2,int r2){
	//printf("%d %d %d %d   %c %c %c %c\n",l,r,l2,r2,a[l],a[r],b[l2],b[r2]);
	string as="";
	if(l==r){
		as+=a[l];
		return as;
	}
	int k,k2;
	//printf("pop...\n");
	for(int i=0;i+l<=r;i++){
		//printf("cmp %d %d  %c %c\n",l,i+l2,a[l],b[i+l2]);
		if(a[r]==b[i+l2]){
			k=i+l;k2=i+l2;break;
		}
	}

	as+=a[r];

	//printf("choose %d %d  %c %c\n",k,k2,a[k],b[k2]);
	if(k2>l2){
		as+=sol(a,b,l,k-1,l2,k2-1);
	}
	//cout<<as<<endl;
	if(k2<r2){
		as+=sol(a,b,k,r-1,k2+1,r2);
	}
	return as;
}
int main(){
	int n;
	string a,b;
	cin>>b>>a;
	n=a.size();
	cout<<sol(a,b,0,n-1,0,n-1);
	return 0;
}
