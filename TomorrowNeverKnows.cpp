#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
using namespace std;

bool IsLeapYear( int year ){
    bool isLeap = false;
    if(year % 100 == 0 && year % 400 == 0)
        isLeap = true;

    if(year % 4 == 0 && year % 100 != 0)
        isLeap = true;

    return isLeap;
}

int main() {
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);

    int month_data[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(day >= month_data[month-1]){
        if( month == 12 ){
            year++;
            month = 1;
            day = 1;
        }
        else if(month == 2 ){
            if(IsLeapYear( year ) && day == 28)
                day = 29;
            else{
                month++;
                day = 1;
            }
        }
        else{
            month++;
            day = 1;
        }

    }
    else
        day++;

    printf("%d-%02d-%02d\n", year, month, day);
    return 0;

}