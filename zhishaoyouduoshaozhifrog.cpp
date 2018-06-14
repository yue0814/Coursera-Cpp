/*********************************************
**文件名：百炼-2812
**Copyright (c) 2015-2025 OrdinaryCrazy
**创建人：OrdinaryCrazy
**日期：20180814
**描述：百炼2812参考答案
**版本：1.0
**********************************************/
#include <stdio.h>
#include <stdlib.h>
struct plant
{
    int x,y;
};
typedef struct plant plant;
plant field[5000];
int r,c,n;
int compare(const void* plant1,const void* plant2)
{
    plant* a = (plant*)plant1;
    plant* b = (plant*)plant2;
    if(a->y - b->y) return a->y - b->y;
    return a->x - b->x;
}
/*****************************************************
**函数名：countsteps
**输入：plant2-第二个水稻的索引 dx-横向跨距 dy-纵向跨距
**输出：这条路线上的步数
******************************************************/
int countsteps(int plant2,int dx,int dy)
{
    plant tmp;
    int steps = 2;
    tmp.x = field[plant2].x + dx;
    tmp.y = field[plant2].y + dy;
    while(tmp.x <= c && tmp.x >= 1 && tmp.y <= r && tmp.y >= 1)
    {
        if(!bsearch(&tmp,field,n,sizeof(plant),compare))
        {
            steps = 0;break;//虽然走了几步，但发现走不出去，这是一条假路
        }
        tmp.x += dx;
        tmp.y += dy;
        steps++;
    }
    return steps;
}
/*********************************************
为了方便查找，我们不妨假设所有的青蛙路线都是从左往右，从上向下的
其实任给三点，就能判断是否为一条青蛙路线，关键在于从最先被踩的两株找跳跃模式
所谓跳跃模式，就是每一步横向跨距和纵向跨距
关键在于判断0号点，3号点，0号点不在稻田内，3号点不在稻田外
**********************************************/
int main()
{
    int i,j,dx,dy,px,py,steps,max = 2;
    scanf("%d%d%d",&r,&c,&n);
    for(i = 0;i < n;i++)
        scanf("%d%d",&field[i].y,&field[i].x);
    qsort(field,n,sizeof(plant),compare);//先行后列，先从上到下，后从左往右
    /**for(i = 0;i < n;i++)
        printf("%d %d\n",field[i].y,field[i].x);**/
    for(i = 0;i < n - 2;i++)
        for(j = i + 1;j < n - 1;j++)
        {
            dx = field[j].x - field[i].x;
            dy = field[j].y - field[i].y;//纵向跨距必为正，横向跨距不一定
            px = field[i].x - dx;
            py = field[i].y - dy;//判断0号点的情况
            if(px <= c && px >= 1 && py <= r && py >= 1) continue;
            if(field[i].y + max*dy > r) break;
            px = field[i].x + max*dx;
            if(px > c || px < 1) continue;//现在已经确定这条路上至少有3个点
            steps = countsteps(j,dx,dy);
            steps > max ? max = steps : 0;
        }
    printf("%d\n",max == 2 ? 0 : max);
    return 0;
}