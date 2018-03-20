#include <iostream>
using namespace std;

int main()
{
    int firstNum = 0, secondNum = 0;
    char operate = 0;
    cin >> firstNum >> secondNum >> operate;

    switch(operate)
    {
    case '+':cout << firstNum + secondNum << endl;break;
    case '-':cout << firstNum - secondNum << endl;break;
    case '*':cout << firstNum * secondNum << endl;break;
    case '/':if (secondNum == 0)
            {
                    cout << "Divided by zero!" << endl;
            } 
            else
            {
                cout << firstNum/secondNum << endl;
            }
            break;
    default: cout << "Invalid operator!" << endl; break;
    }
    return 0;
}