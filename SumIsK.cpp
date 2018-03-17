#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int nums[n];
    vector<int> vec;
    string s = "no";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        if (nums[i] <= k)
            vec.push_back(nums[i]);
    }
    for (auto it = vec.begin(); it != vec.end(); it++){
        for (auto begin = it + 1; begin != vec.end(); begin++){
            if (*it + *begin == k)
                s = "yes";
            else
                continue;
        }
    }
    cout << s << endl;
    return 0;

}