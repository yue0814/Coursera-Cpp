//
//  ArrayReverse.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (n--) { //常用的倒序计数循环，等价于while(n-->0)
        cout << a[n];
        if (n > 0) cout << " "; //如果不是最后一个数那么就要用空格分隔开
    }
    cout << endl;
    return 0;
}
