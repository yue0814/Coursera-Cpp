#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 10; i <= n; i++){
        int tens = i / 10;
        int digits = i % 10;
        if (i % (tens + digits) == 0)
            cout << i << endl;
    }
    return 0;
}