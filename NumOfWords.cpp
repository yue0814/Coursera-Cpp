#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char s[80];
    int cnt[5] = {0, 0, 0, 0, 0};
    cin.getline(s, 80);
    int start = 0;
    while (s[start] != '\0'){
        if (s[start] == 'a')
            cnt[0]++;
        else if (s[start] == 'e')
            cnt[1]++;
        else if (s[start] == 'i')
            cnt[2]++;
        else if (s[start] == 'o')
            cnt[3]++;
        else if (s[start] == 'u')
            cnt[4]++;
        start++;
    }
    for (int i = 0; i < 5; i++)
        cout << cnt[i] << " ";
    cout << endl;
    return 0;
}
