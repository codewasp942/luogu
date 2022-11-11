#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1E5+1;
int CollectMin[4*MAXN];
int a[MAXN];

void PushUpNode(int* CollectMem,int NowID);
void BuildTree(int* CollectMem,int* FromMem,int l,int r,int NowID=1);
void SetVal(int* CollectMem,int Pos,int Val,int l,int r,int NowID=1);
int QuerySec(int* CollectMem,int L,int R,int l,int r,int NowID=1);


int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    BuildTree(CollectMin,a,1,n);
    int q;
    cin>>q;
    string op;
    int a,b;
    for(int i=1;i<=q;i++){
        cin>>op>>a>>b;
        if(op=="query"){
            cout<<QuerySec(CollectMin,a,b,1,n)<<endl;
        }else{
            SetVal(CollectMin,a,b,1,n);
        }
    }
    return 0;
}

void PushUpNode(int* CollectMem,int NowID){
    CollectMem[NowID]=CollectMem[NowID<<1]+CollectMem[(NowID<<1)+1];
}
void BuildTree(int* CollectMem,int* FromMem,int l,int r,int NowID){
    if(l==r){
        CollectMem[NowID]=FromMem[l];
    }else{
        int mid=l+((r-l)>>1);
        BuildTree(CollectMem,FromMem,l,mid,(NowID<<1));
        BuildTree(CollectMem,FromMem,mid+1,r,((NowID<<1)+1));
        PushUpNode(CollectMem,NowID);
    }
}

void SetVal(int* CollectMem,int Pos,int Val,int l,int r,int NowID){
    if(l==r){
        CollectMem[NowID]=Val;
    }else{
        int mid=l+((r-l)>>1);
        if(Pos<=mid){
            SetVal(CollectMem,Pos,Val,l,mid,NowID<<1);
        }else{
            SetVal(CollectMem,Pos,Val,mid+1,r,(NowID<<1)+1);
        }
        PushUpNode(CollectMem,NowID);
    }
}

int QuerySec(int* CollectMem,int L,int R,int l,int r,int NowID){
    if(L<=l && r<=R){
        return CollectMem[NowID];
    }else{
        int mid=l+((r-l)>>1);
        int ans;bool f=0;
        int res=0;
        if(L<=mid){
            ans=QuerySec(CollectMem,L,R,l,mid,NowID<<1);
            f=1;
        }
        if(R>mid){
            if(f){
                ans=ans+QuerySec(CollectMem,L,R,mid+1,r,(NowID<<1)+1);
            }else{
                ans=QuerySec(CollectMem,L,R,mid+1,r,(NowID<<1)+1);
            }
        }
        return ans;
    }
}
