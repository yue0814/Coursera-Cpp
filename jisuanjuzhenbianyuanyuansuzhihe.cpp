#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int m=0, n=0, sum=0;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int a=0;
                cin >> a;
                if (i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    sum += a;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}