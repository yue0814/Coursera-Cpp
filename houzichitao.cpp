#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans;
    cin>>n;
    for(int i=1;;i++){  //枚举最后一个猴子拿走的桃子数
        ans=i*n+1;
        int j;
        for(j=1;j<n;j++){
            if(ans%(n-1)!=0)break;
            ans=ans/(n-1)*n+1;
        }
        if(j==n)break;
    }
    printf("%d",ans);
    return 0;
}