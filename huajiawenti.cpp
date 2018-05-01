#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

int Wall[15][15];
int Paint_Y[15][15];
char col[15];
int count = 0;
int ans = 0;
int result[15];

int  guess(int size)
{
    int c, r;

    for(r = 1; r < size; r++)
    {
       for(c = 1; c < size + 1; c++)
        {
            Paint_Y[r+1][c] = (Wall[r][c] + Paint_Y[r][c] + Paint_Y[r][c-1] + Paint_Y[r][c+1] + Paint_Y[r-1][c])%2;
            if(Paint_Y[r+1][c] == 1)
                count ++;
        }

    }

    for(c = 1; c < size + 1; c ++)
    {
        if((Paint_Y[size][c] + Paint_Y[size][c-1] + Paint_Y[size][c+1] + Paint_Y[size-1][c])%2 != Wall[size][c])
            return 0;
    }
    if(count < ans)
        ans = count;
    return 1;

}

void get_first_line(int k,int size)
{
    int j = size;
    while(j > 0)
    {
        Paint_Y[1][j] = k % 2;
        k /= 2;
        j --;
    }
}
int main()
{
    int cases,i,j,k,r,c,size;
    char tmpc;

    memset(Wall,0,sizeof(Wall));
    memset(Paint_Y,0,sizeof(Paint_Y));


    scanf("%d",&cases);




    for(i = 0; i < cases; i ++)
    {
        scanf("%d",&size);

        for(r = 0; r < size + 1; r ++)
            Paint_Y[r][0] = Paint_Y[r][size+2] = 0;
        for(c = 0; c < size + 2; c++)
            Paint_Y[0][c] = 0;

        for(r = 1; r < size + 1; r++ )
        {
            scanf("%s",col);
            for(c = 1; c < size + 2; c++)
            {

                if(col[c-1] == 'y')
                    Wall[r][c] = 0;
                else
                    Wall[r][c] = 1;
            }
        }

        ans = size * size + 1;
        for(j = 0; j != (1<<size); j++)
        {
            count = 0;

            get_first_line(j,size);

            for(k = 1; k < size + 1; k++)
            {
                if(Paint_Y[1][k] == 1)
                     count ++;
            }
            guess(size);
        }
        result[i] = ans;


    }

    for(i = 0; i < cases; i++)
    {
        if(result[i] < (size * size + 1))
            printf("%d",result[i]);
        else
            printf("inf");
        printf("\n");
    }





    return 0;


}
