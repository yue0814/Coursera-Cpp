//
//  OddSum.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int m, n, result = 0;
    cin >> m >> n;
    while (m <= n){
        if (m % 2 == 1){
            result += m;
        }
        m++;
    }
    cout << result << endl;
    return 0;
}
