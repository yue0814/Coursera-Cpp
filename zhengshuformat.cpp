#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num;
    cin >> num;
    cout << hex << num << endl;
    cout.fill('0');
    cout.unsetf(ios::hex);
    cout.setf(ios::dec);
    cout << setw(10) << num << endl;
    return 0;
}