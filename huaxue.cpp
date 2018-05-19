#include <iostream>
//#include <memory>
#include <map>
#include <algorithm>
using namespace std;

struct coordinate{   //高度的坐标类
    int x, y;
};

//C++ STL中Map的按Key排序和按Value排序 https://www.cnblogs.com/lakeone/p/5599047.html
//自定义map容器中的比较大小顺序，按Key排序
struct MyCompare{   
    bool operator()(const int& a, const int& b){    //这里或者写成 bool operator()(int a, int b) const{ http://zh.cppreference.com/w/cpp/algorithm/sort
        return a < b;
    }
};

int main() {
    int R, C;
    int L[102][102];  //滑行长度
    int H[102][102];  //高度
    //memset(L, 1, sizeof(L));   //memset函数直接将数组中的元素全部置成 1  http://zh.cppreference.com/w/cpp/string/byte/memset
    //memset(H, 10000, sizeof(H));   //所有位置的高度全部置为 10000，此处不行！ http://blog.csdn.net/my_business/article/details/40537653
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < 102; j++){
            L[i][j] = 1;
            H[i][j] = 10000;
            //cout << L[i][j] << " " << H[i][j] << "   ";
        }
        //cout << endl;
    }
    int maxL = 0;
    coordinate position;
    multimap<int, coordinate, MyCompare> height;   //这里要用multimap容器，因为可能出现相同高度的位置点！
    multimap<int, coordinate, MyCompare>::iterator hi;

    cin >> R >> C;
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            cin >> H[i][j];
            position.x = i;
            position.y = j;
            height.insert({ H[i][j], position });   //把每个位置的高度和坐标放入map容器中
        }
    }

    int Lx, Ly; //位置的坐标
    for (hi = height.begin(); hi != height.end(); hi++){
        //cout << hi->first << " " << hi->second.x << " " << hi->second.y << " " << H[hi->second.x][hi->second.y] << endl;
        Lx = hi->second.x;
        Ly = hi->second.y;
        if (H[Lx][Ly] <= H[Lx - 1][Ly] && H[Lx][Ly] <= H[Lx + 1][Ly] && H[Lx][Ly] <= H[Lx][Ly - 1] && H[Lx][Ly] <= H[Lx][Ly + 1]){
            L[Lx][Ly] = 1;
        }
        else{
            if (H[Lx][Ly] > H[Lx - 1][Ly])
                L[Lx][Ly] = max(L[Lx][Ly], L[Lx - 1][Ly] + 1);
            if (H[Lx][Ly] > H[Lx + 1][Ly])
                L[Lx][Ly] = max(L[Lx][Ly], L[Lx + 1][Ly] + 1);
            if (H[Lx][Ly] > H[Lx][Ly - 1])
                L[Lx][Ly] = max(L[Lx][Ly], L[Lx][Ly - 1] + 1);
            if (H[Lx][Ly] > H[Lx][Ly + 1])
                L[Lx][Ly] = max(L[Lx][Ly], L[Lx][Ly + 1] + 1);
        }
        if (maxL < L[Lx][Ly])
            maxL = L[Lx][Ly];
    }

    cout << maxL << endl;

    return 0;
}