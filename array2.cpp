#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2{
        int arr[10][10];
    public:
        Array2();
        Array2(int, int);
        int*  operator [](int i) {return arr[i];}  
        int operator()(int i, int j){return arr[i][j];}  
        Array2(Array2& c){
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++)  
                {
                    arr[i][j] = c.arr[i][j];
                }
            }  
        };
};
Array2::Array2(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++)  
        {  
        arr[i][j] = 0;  
        }
    }  
}

Array2::Array2(int a, int b)  
{  
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++)  
        {  
        arr[i][j] = 0;  
        }
    }
}

int main() {
    Array2 a(3, 4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}