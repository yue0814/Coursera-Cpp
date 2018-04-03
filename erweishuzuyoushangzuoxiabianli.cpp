#include <iostream>
//#include <vector>
using namespace std;

int main()
{
    int row = 0, rol = 0;
    cin >> row >> rol;
//  vector<vector<int>> array(row, rol);//使用vector提交作业提示：Compile Error，难道使用方法有误？本地运行时正确的
    int array[100][100] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < rol; j++)
        {
            cin >> array[i][j];
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < row+rol-1; i++)
    {
        x = i > rol-1? i-rol+1 : 0;
        y = i-x;
        while (x <= row-1 && y >= 0)
        {
            cout << array[x][y] << endl;
            x++;
            y--;
        }
    }
    return 0;
}