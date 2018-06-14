#include<stdio.h>
#include<string.h>
#include <queue>
#include <stack>
#include <algorithm>
#define Max 21
 
using namespace std;
 
int n, m;
bool vis[30][30];
int x[]={-1, 1, -2, 2,-2, 2,-1, 1};
int y[]={-2,-2, -1,-1, 1, 1, 2, 2};
//从当前马的位置可以走到的8个位置
//在满足字典序最小的前提下 这8个方向的遍历先后不能变动
bool ok;
 
struct node
{
    int col, row;
}path[1000];
int e=0;
 
bool sure(int i, int j)
{
    if(i>=1 && i<=n && j>=1 && j<=m)
        return true;
    else
        return false;
}
 
void dfs(int i, int j, int cnt)//cnt表示我们在当前这次dfs偶中搜索到的节点
{
    path[cnt].col=j; path[cnt].row=i;//当前位置进入路径队列
 
    if(cnt==n*m){
        ok=true; return; //所有节点都已经遍历到
    }//在这return 开始往回回溯
 
    int a, b;
    for(int k=0; k<8; k++){
 
        a=i+x[k];
        b=j+y[k];
        if(sure(a, b) && !vis[a][b]){
            vis[a][b]=true;
            dfs(a, b, cnt+1);
            if(ok==true) return;//在这return 返回主函数
            vis[a][b]=false;
        }
    }
    return;
}
 
int main()
{
    int tg; scanf("%d", &tg);
    int cnt=1;
 
    while(tg--)
    {
        scanf("%d %d", &n, &m);
        ok=false;
        if(n==1 && m==1){
            printf("Scenario #%d:\n", cnt++);
            printf("A1\n\n");
            continue;
        }
        else{
            ok=false;
            memset(vis, false, sizeof(vis));
            vis[1][1]=true;
            e=0;
            dfs(1, 1, 1);
 
            if(!ok){
                printf("Scenario #%d:\n", cnt++);
                printf("impossible\n\n");
            }
            else{
                printf("Scenario #%d:\n", cnt++);
                for(int i=1; i<=n*m; i++)
                {
                    printf("%c%d", path[i].col+'A'-1, path[i].row );
                }
                printf("\n\n");
            }
        }
    }
    return 0;
}