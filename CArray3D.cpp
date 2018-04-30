#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D
{
    public:
        template <class T1>
        class CArray2D{
            T1 *a;
            int i, j;
            public:
                CArray2D() {a=nullptr;}
                CArray2D(int a1, int a2): i(a1), j(a2) {
                    a = new T1[i*j];
                }
                ~CArray2D() {
                    if (a != nullptr) delete []a;
                }
                T1 *operator[] (int a1) {
                    return a + a1*j;
                }

        };
        CArray3D() {array2D = nullptr;}
        CArray3D(int a1, int a2, int a3) {
            array2D = new CArray2D<T>* [a1];
            for (int m=0; m < a1; m++){
                array2D[m] = new CArray2D<T>(a2, a3);
            }
        }
        CArray2D<T>& operator[](int i){
            return *array2D[i];
        }
        ~CArray3D(){
            if (array2D != nullptr) delete []array2D;
        }
    private:
        CArray2D<T>** array2D;
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
return 0;
}