#include <iostream>
using namespace std;
/*
下面程序输出的结果是：

0

5*/
class A {
public:
    int val;
// 在此处补充你的代码
    A() {val = 0;}
    int& GetObj(){
        return val;}
};
int main() {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}