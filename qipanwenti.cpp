#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 9
 
int n, k, sum, sumk;
char map[MAX][MAX];
int visit[100] = {0};
 
void dfs(int a, int b)
{
    int i, j;
    if (sumk == k)
    {
        sum++;
        return;
    }
    /* 置当前列不可放 */
    visit[b] = 1;
    /* 从下一行开始搜索 */
    for (i = a + 1; i <= n; i++)
    {
        /* 每一行从左向右搜索 */
        for (j = 1; j <= n; j++)
        {
            if (map[i][j] == '#' && visit[j] == 0)
            {
                /* 格子可放棋子数 + 1 */
                sumk++;
                /* 继续向下搜索 */
                dfs(i, j);
                /* 回溯时棋子数 - 1 */
                sumk--;
            }
        }
    }
    /* 回溯时重置列可放 */
    visit[b] = 0;
}
 
int main()
{
    int i, j;
    while(1)
    {
        scanf("%d%d", &n, &k);
        if(n == -1 && k == -1) break;
        sum = 0;
        for (i = 1; i <= n; i++)
        {
            getchar();
            for(j = 1; j <= n; j++)
            {
                scanf("%c", &map[i][j]);
            }
        }
        for (i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if (map[i][j] == '#')
                {
                    sumk = 1;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n", sum);
    }
    //system("pause");
    return 0;
}