#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int ans,n,m,len,flag,num;
int wsf[10],b[10];
char a[10];
void dfs(int now)
{
    if (now==len-1)
    {
        int tmp=0,tans=0;
        for (int i=0;i<len;i++)
        {
            int snow=a[i]-'0';
            tmp=tmp*10+snow;
            if (wsf[i]==1)
            {
                tans+=tmp;
                tmp=0;
            }
        }
// for (int i=0;i<len;i++)
// cout<<wsf[i]<<' ';
// cout<<endl;
        if (tans>ans && tans<=n) 
        {
            ans=tans,flag=1,num=0;
                    for (int i=0;i<len;i++)
                    {
                            int snow=a[i]-'0';
                            tmp=tmp*10+snow;
                            if (wsf[i]==1)
                            {
                                    num++;
                    b[num]=tmp;
                                    tmp=0;
                            }
                    }

        }
        else if (tans==ans) flag=0;
        return ;
    }
    dfs(now+1);
    wsf[now]=1;
    dfs(now+1);
    wsf[now]=0;
    return ;
}
int main()
{
    while(1)
    {
        scanf("%d",&n);
        scanf("%s",a);
        ans=-1;
        if (n==0 && a[0]=='0') return 0;
        memset(wsf,0,sizeof(wsf));
        len=strlen(a);
        wsf[len-1]=1;
        flag=1;
        dfs(0);
        if (flag==1 && ans!=-1)
        {
            printf("%d",ans);
            for (int i=1;i<=num;i++)
            printf(" %d",b[i]);
            printf("\n");
        }
        else if (flag==0) printf("rejected\n");
        else if (ans==-1) printf("error\n");

    }
}