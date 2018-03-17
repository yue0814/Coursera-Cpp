//
//  AppleandWorm.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n, x, y, h;
    cin >> n >> x >> y;
    if (y % x == 0)
        h = y / x;
    else
        h = y / x + 1;
    
    if (n - h < 0)
        cout << 0 << endl;
    else
        cout << n - h << endl;
    return 0;
}
