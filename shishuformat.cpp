#include <iostream>
using namespace std;

int main()
{
    double num;
    cin >> num;
    cout.setf(ios::fixed);
    cout.precision(5);
    cout << num << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout.precision(7);
    cout << num << endl;
    return 0;

}