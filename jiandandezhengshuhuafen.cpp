#include <stdio.h>
long long GetPartitionCount(int n,int max)
{
    if(n==1||max==1) return 1;
    else if(n<max) return GetPartitionCount(n,n);
    else if(n==max) return 1+GetPartitionCount(n,max-1);
    else return GetPartitionCount(n,max-1)+GetPartitionCount(n-max,max);
}
int main(int argc, char *argv[])
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",GetPartitionCount(n,n));
    }
    return 0;
}