//注意在windows下编程控制台默认为80字符宽度，到了80个字符会自动换行，其他环境下不一定如此，所以不用作特殊处理
#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int words = 0, sum = 0;
    cin >> words;
    char str[41]={0};
    for (int i = 0; i < words; i++)
    {
        cin >> str;
        if (sum + 1 + strlen(str) > 80)
        {
            cout << endl;               
            sum = 0;        
        } 
        else if(i>0)
        {
            cout << " ";
            sum++;  
        }
        cout << str;
        sum += strlen(str);
    }
    return 0;
}