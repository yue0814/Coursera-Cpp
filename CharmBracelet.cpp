#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxN 3402   //注：此处没有 ; 号！
#define maxM 12880

int main(){
    int N, M, W[maxN + 1], D[maxN + 1];
    int f[maxM + 1];
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> D[i];
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= N; i++){
        for (int j = M; j >= W[i]; j--)
            f[j] = max(f[j], f[j - W[i]] + D[i]);
    }

    cout << f[M] << endl;

    return 0;
}