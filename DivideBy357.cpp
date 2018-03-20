#include <iostream>
using namespace std;

int main(){
    int num;
    bool flag = false;
    while (cin >> num){
        if (num % 3 == 0){
            cout << "3 ";
            flag = true;
        }
        if (num%5 == 0)
        {
            cout << "5 ";
            flag = true;
        }
        if (num%7 == 0)
        {
            cout << "7";
            flag = true;
        }
        if (flag == false)
        {
            cout << "n";
        }
        cout << endl;
        flag = false;
    }
    return 0;
}