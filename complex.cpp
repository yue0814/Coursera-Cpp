#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
/*
3+4i

5+6i

*/
class Complex {
private:    
    double r,i;
public:    
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex& operator= (const char *s){
        string str = s;
        int pos = str.find("+", 0);
        string strReal = str.substr(0, pos);
        r = atof(strReal.c_str());
        string strImaginary = str.substr(pos + 1, str.length() - pos - 2);//分离出虚部代表的字符串
		i = atof(strImaginary.c_str());
		return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}