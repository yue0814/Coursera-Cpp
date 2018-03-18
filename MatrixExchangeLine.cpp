#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }
    int n, m;
    cin >> n >> m;
    if (n > 4 || m > 4 || n < 0 || m < 0)
        cout << "error" << endl;
    else{
    int temp[5];
    for (int i = 0; i < 5; i++){
        temp[i] = arr[n][i];
        arr[n][i] = arr[m][i];
        arr[m][i] = temp[i];
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout<< setw(4)<< arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
    }
    return 0;
}