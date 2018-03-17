#include <iostream>
using namespace std;

int main ()
{
    int a, cnt = 5, n, sum = 0;
    cin >> a;
    while (cnt){
        cin >> n;
        if (n < a)
            sum += n;
        cnt--;
    }
    cout << sum << endl;
    return 0;
}