//
//  HighestScore.cpp
//  Working
//
//  Created by 彭越 on 2018/3/16.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int scores[n];
    int max_score = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        if (max_score < scores[i])
            max_score = scores[i];
    }
    cout << max_score << endl;
    return 0;
}

