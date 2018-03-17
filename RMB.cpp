#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ns[6] = {100, 50, 20, 10, 5, 1};
    for (int i = 0; i < 6; i++){
        int num = n / ns[i];
        if (num > 0){
            n = n % ns[i];
            cout << num << endl;
            continue;
        }
        else{
            cout << 0 << endl;
            continue;
        }
    }
    return 0;
}