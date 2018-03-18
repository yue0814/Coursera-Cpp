#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char sentence[500];
    cin.getline(sentence, 500);
    int maxLength = 0;
    int maxStart = 0, maxEnd = 0;
    int start = 0, end = 0;
    while (sentence[end] != '.'){
        while (sentence[end] != ' ')
            end++;
        if (end - start > maxLength){
            maxLength = end - start;
            maxStart = start;
            maxEnd = end;
            cout << maxLength << " " << maxStart << " " << maxEnd << endl;
        }
        else{
        start = end + 1;
        end += 1;
        }
    }
    for (int i = maxStart; i < maxEnd; i++)
        cout << sentence[i];
    return 0;
}
