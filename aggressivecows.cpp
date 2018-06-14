#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1e5+100;
int m[MAXN];
int N,C;
bool js(int x){
    int t=m[0];
    int cnt=1;
    for(int i=1;i<N;i++){
        if(m[i]-t>=x)cnt++,t=m[i];
    }
    if(cnt>=C)return true;
    else return false;
}
int erfen(int l,int r){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(js(mid))l=mid+1;
        else r=mid-1;
    }
    return l;
}
int main(){
    while(~scanf("%d%d",&N,&C)){
        for(int i=0;i<N;i++)scanf("%d",m+i);
        sort(m,m+N);
        printf("%d\n",erfen(0,m[N-1]-m[0])-1);//不明觉厉
    }
    return 0;
}