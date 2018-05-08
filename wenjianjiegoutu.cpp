#include <iostream>  
#include <string>
#include <set>  
using namespace std;

int n = 0;//层数  
int m = 1;//第几组数据  
bool have_print;
bool stop = false;

void print(){
    if (have_print == false){
        have_print = true;
        if (m != 1) 
            cout << endl;
        cout << "DATA SET " << m << ":" << endl << "ROOT" << endl;
    }
}

void fun(void){
    string str;
    set<string> s;
    while (cin >> str){
        switch (str[0]){
        case '#':
            stop = true;
            return;
        case 'f':
            print();
            s.insert(str);
            break;
        case 'd':
            print();
            n++;
            for (int i = 0; i<n; i++){
                cout << "|     ";
            }
            cout << str << endl;
            fun();
            break;
        case ']':
            for (set<string>::iterator i = s.begin(); i != s.end(); i++){
                for (int j = 0; j<n; j++){
                    cout << "|     ";
                }
                cout << *i << endl;
            }
            n--;
            return;
        case '*':
            for (set<string>::iterator i = s.begin(); i != s.end(); i++){
                cout << *i << endl;
            }
            m++;
            return;
        }
    }
}

int main(){
    while (!stop){
        have_print = false;
        fun();
    }

    return 0;
}