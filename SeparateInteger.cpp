//
//  SeparateInteger.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int number;
    cin >> number;
    int hundred = number / 100;
    int ten = (number % 100) / 10;
    int digit = number % 10;
    cout << hundred << endl;
    cout << ten << endl;
    cout << digit << endl;
    return 0;
}

