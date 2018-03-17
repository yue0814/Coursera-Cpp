//
//  AbsoluteDifferenceLargestOddSmallestEven.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int nums[6];
    for (int i = 0; i < 6; i++)
        cin >> nums[i];
    // bubble sort
    for (int i = 0; i < 6; i++){
        for (int j = 1; j < 6 - i; j++){
            if (nums[j - 1] > nums[j]){
                int temp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    int begin = 0, end = 5;
    while (nums[begin] % 2 != 0){
        begin++;
    }
    while (nums[end] % 2 == 0){
        end--;
    }
    if (nums[begin] - nums[end] < 0)
        cout << nums[end] - nums[begin] << endl;
    else
        cout << nums[begin] - nums[end] << endl;
    return 0;
}
