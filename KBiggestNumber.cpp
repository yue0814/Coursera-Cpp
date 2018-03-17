#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N;
    cin >> K;
    int nums[N];
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    // Bubble Sort
    for (int i = 0; i < N - 1; i++){
        for (int j = 1; j < N - i; j++){
            if (nums[j - 1] > nums[j]){
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
    int end = N;
    while (K--){
        end--;
    }
    cout << nums[end] << endl;
    return 0;
}