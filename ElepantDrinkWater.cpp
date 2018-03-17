//
//  ElepantDrinkWater.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//
#define PI 3.14159

#include <iostream>
using namespace std;
int main()
{
    int h, r;
    cin >> h >> r;
    double bucket_volume = PI * r * r * h / 1000;
    int num_bucket = 20 / bucket_volume;
    cout << num_bucket + 1 << endl;
    return 0;
}
