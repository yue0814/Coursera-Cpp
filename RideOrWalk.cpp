#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        float tBike = 0, tWalk = 0;
        cin >> temp;
        tBike = (float)temp/3.0 + 50;
        tWalk = (float)temp/1.2;
        if (tBike < tWalk)
        {
            cout << "Bike" <<endl;
        } 
        else if(tBike > tWalk)
        {
            cout << "Walk" << endl;
        }
        else
        {
            cout << "All" << endl;
        }
    }
    return 0;
}
