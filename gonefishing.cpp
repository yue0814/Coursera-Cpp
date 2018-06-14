#include <iostream>
#define maxn 30
 
using namespace std;
 
int num, hour,ans,anst;
int f[maxn],d[maxn],t[maxn],ft[maxn];
int res[maxn] , temp[maxn];
void solve()
{
   t[0] = 0;
 
   //统计不同的停留方案所需要的停留时间
   for(int i = 1 ; i < num; i ++) t[i] += t[i-1];
 
   //以5分钟为计量单位的总时间
   int h = hour*12;
   int pos;
   ans  = -1 ;
 
   for(int k = 0 ; k < num ; k ++)
   {
 
       anst = 0;
 
       //ft数组存的是f数组的副本，因为在计算过程中，需要改变ft数组的值；
       //temp数组存储的是当前情况下，在每个湖停留的时间的列表
       for(int i = 0 ; i < num ; i ++) temp[i] = 0 ,ft[i] = f[i];
 
       //去掉路上的时间，之后钓鱼的总时间
       int th = h - t[k];
 
       while(th > 0)
       {
          pos = 0;
          for(int j = 0 ; j <= k ; j ++)
          {//找到当前时间，能钓到最大量的鱼，所在的湖
              if(ft[j] > ft[pos])
                pos  = j;
          }
        //等于号不能去掉。如果在pos位置所能钓到的鱼的数量等于0，
        //那么这一个时间单位将没有必要放在pos所在的湖（可能更新到第一个湖上）
         if(ft[pos] <= 0) break;
          anst += ft[pos];//更新鱼数量
          ft[pos] -= d[pos];//更新所能钓到的鱼的数量
          temp[pos] ++;//更新pos位置停留时间信息
 
          th --;
       }
       //剩余时间全部加在第一个湖上
       if(th > 0) temp[0] += th;
 
       if(anst > ans)
       {//更新结果值和停留时间列表
           ans = anst;
           for(int i = 0 ; i < num ; i ++) res[i] = temp[i];
       }
       else if(anst == ans)
       {//判断并更新停留时间列表
           bool flag = true;
 
           for(int i = 0 ; i < num ; i ++)
              if(temp[i] > res[i])
              {
                    flag = false;
                    break;
              }else if(temp[i] < res[i]) break;
           if(!flag)
               for(int i = 0 ; i < num ; i ++) res[i] = temp[i];
       }
   }
}
void print()
{//输出结果
    for(int i = 0 ; i < num - 1 ; i ++) cout<<res[i]*5<<", ";
    cout<<res[num-1]*5<<endl;
 
    cout<<"Number of fish expected: "<<ans<<endl;
    cout<<endl;
}
int main()
{
    while(cin>>num,num)
    {
        cin>>hour;
        for(int i = 0 ; i < num ; i ++) cin>>f[i] ;
        for(int i = 0 ; i < num ; i ++) cin>>d[i] ;
        for(int i = 1 ; i < num ; i ++) cin>>t[i] ;
 
        solve();
        print();
    }
    return 0;
}