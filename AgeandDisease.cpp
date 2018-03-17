#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ages[n];
    for (int i = 0; i < n; i++)
        cin >> ages[i];
    double cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++){
        if (ages[i] <= 18)
            cnt1 += 1;
        else if (ages[i] >= 19 && ages[i] <= 35)
            cnt2 += 1;
        else if (ages[i] >= 36 && ages[i] <= 60)
            cnt3 += 1;
        else
            cnt4 += 1;
    }
    double rate1 = cnt1 / n;
    double rate2 = cnt2 / n;
    double rate3 = cnt3 / n;
    double rate4 = cnt4 / n;
    cout << "1-18: " << fixed << setprecision(2) << rate1 * 100 << '%' << endl;
    cout << "19-35: " << fixed << setprecision(2) << rate2 * 100 << '%' << endl;
    cout << "36-60: " << fixed << setprecision(2) << rate3 * 100 << '%' << endl;
    cout << "60-: " << fixed << setprecision(2) << rate4 * 100 << '%' << endl;
    return 0;
}