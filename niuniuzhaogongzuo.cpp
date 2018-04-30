#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    map<int,int> DP;
    for (int i=0;i<N;i++)
    {
        int di, pi;
        cin >> di >> pi;
        DP[di] = pi;
    }
    vector<int> A;
    for (int i=0; i<M;i++)
    {
        int ai;
        cin >> ai;
        A.push_back(ai);
    }
    for (int i=0;i<M;i++)
    {
        map<int,int>::iterator it;
        for (it = DP.begin(); it != DP.end(); it++)
        {
            if (it -> first < A[i]) continue;
            else if (it -> first == A[i]) {cout << it -> second << endl; break;}
            else{
                it--;
                cout << it -> second << endl;
                break;
            }
        }
    }
    return 0;
}