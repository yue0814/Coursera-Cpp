#include <iostream>
using namespace std;

int main(){
    double N;
    double K;
    while (cin >> N >> K){
        double total = 0;
        double housePrice = 2000000;
        double increaseRate = K / 100;
        total += N;
        if (total * 10000 >= housePrice){
            cout << 1 << endl;
            continue;
        }
        for (int i = 2; i <= 20; i++){
            housePrice *= (1 + increaseRate);
            total += N;
            if (total * 10000 >= housePrice){
                cout << i << endl;
                break;
            }
        }
        if (total * 10000 < housePrice){
            cout << "impossible" << endl;
            continue;
            }
        else
            continue;

    }
    return 0;
}