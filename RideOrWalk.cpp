#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dist[n];
    for (int i = 0; i < n; i++)
        cin >> dist[i];
    double time_before_ride = (27 + 23);
    for (int i = 0; i < n; i++){
        double time_walk = dist[i] / 1.2;
        double time_ride = time_before_ride + dist[i] / 3;
        if (time_ride < time_walk)
            cout << "Bike" << endl;
        else if (time_ride > time_walk)
            cout << "Walk" << endl;
        else
            cout << "All" << endl;
    }
    return 0;
}