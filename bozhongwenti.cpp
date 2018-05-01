#include <iostream>
#include <cstring>
using namespace std;
#define N 9
#define L 9
//    a, b, c, d, e, f, g, h, i
int cases[L][N] = {{1, 1, 0, 1, 1, 0, 0, 0, 0}
    ,{1, 1, 1, 0, 0, 0, 0, 0, 0}
    ,{0, 1, 1, 0, 1, 1, 0, 0, 0}
    ,{1, 0, 0, 1, 0, 0, 1, 0, 0}
    ,{0, 1, 0, 1, 1, 1, 0, 1, 0}
    ,{0, 0, 1, 0, 0, 1, 0, 0, 1}
    ,{0, 0, 0, 1, 1, 0, 1, 1, 0}
    ,{0, 0, 0, 0, 0, 0, 1, 1, 1}
    ,{0, 0, 0, 0, 1, 1, 0, 1, 1}};
int a[N];

int minCount = 4 * L + 1;
int result[L];

void guess(int (&count)[L], int l, int currentCount){
    //枚举到的方案大于minCount时直接放弃
    if (currentCount > minCount) {
        return;
    }
    if (l == L) {
        int j;
        for(j = 0; j < N; j++) {
            //检测第j个时钟是否满足指向12点的要求
            int sum = a[j];
            for(int ll = 0; ll < L; ll++) {
                sum += count[ll] * cases[ll][j];
            }
            if (sum % 4 != 0) {
                break;
            }
        }

        if (j == N) {
            if (currentCount < minCount) {
                minCount = currentCount;
                memcpy(result, count, sizeof(count));
            }
        }

        return;
    }
    int nextLine = l + 1;
    for(count[l] = 0; count[l] < 4; count[l]++) {
        guess(count, nextLine, currentCount + count[l]);
    }
}

int main()
{
//  freopen("in.txt", "r", stdin);
    memset(result, 0, sizeof(result));

    bool isResult = true;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] % 4 != 0) {
            isResult = false;
        }
    }
    if (isResult) {
        return 0;
    }

    //记录采取方案的次数
    int count[L];
    guess(count, 0, 0);
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < result[i]; j++) {
            cout << i + 1 << " ";
        }
    }
    return 0;
}