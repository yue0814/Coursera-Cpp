#include <iostream>
using namespace std;

int main()
{
    int n;
    bool flag = false;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i){
            cout << arr[i] << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << 'N' << endl;
    return 0;

}