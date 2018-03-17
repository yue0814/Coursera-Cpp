//
//  SumOfFraction.cpp
//  Working
//
//  Created by Yue Peng on 2018/3/17.
//  Copyright © 2018年 PY. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int gcd(int a, int b){
    int c;
    if (a > b){
        int temp = b;
        b = a;
        a = temp;
    }
    while (a != 0){
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}


int main(){
    int n;
    cin >> n;
    int sumn = 0, sumd = 1;
    while (n--){
        int num, deno;
        char slash;
        cin >> num >> slash >> deno;
        sumn = sumn * deno + sumd * num;
        // sumd = sumd * deno; //  might produce overflow
        int gcd1 = gcd(sumn, deno);
        sumn /= gcd1;
        deno /= gcd1;
        sumd = sumd * deno;

        cout << sumn << '/' << sumd << endl;
    }
    
    int gcd_num = gcd(sumd, sumn);
    sumd /= gcd_num;
    sumn /= gcd_num;
    if (sumd > 1)
        cout << sumn << '/' << sumd << endl;
    else
        cout << sumn << endl;
    return 0;
}
