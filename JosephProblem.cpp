//
//  JosephProblem.cpp
//  Working
//
//  Created by Yue Peng on 2018/3/17.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int succedent[300]; // after
int precedent[300]; // before

int main()
{
    int n, m;
    while (true){
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        // initialize the circle
        for (int i = 0; i < n - 1; i++) {
            succedent[i] = i + 1;
            precedent[i + 1] = i;
        }
        succedent[n - 1] = 0;
        precedent[0] = n - 1;
    int current = 0;
    while (true) {
        //如果一共要报m次号，那么取m-1次succedent之后就是需要退出的那只猴子
        for (int count = 0; count < m - 1; count++)
            current = succedent[current];
        
        int pre = precedent[current];
        int suc = succedent[current];
        //让current号猴子退出很简单，就是把前一位的“下一位”指向current的下一位，
        //下一位的“前一位”指向current的前一位就好了
        succedent[pre] = suc;
        precedent[suc] = pre;
        if (pre == suc) {
            //如果只剩下两个了，那么每个人的前位和后位就是同一个了。
            //current是退出的，那么另一个就是剩下的。
            //我们的序号是从0编号的，输出时要加一
            cout << pre + 1 << endl;
            break;
        }
        current = suc;
    }
}
    return 0;
}
