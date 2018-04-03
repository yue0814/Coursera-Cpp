#include <iostream>
#include <vector>
using namespace std;

int changeOrder(char str[], int i)
{
    if (str[i] == '\0')
    {
        return 0;
    }
    else
    {
        changeOrder(str, i+1);
    }
    cout << str[i];
    return 0;
}
int main()
{
    char str[500], word[500];
    cin.getline(str, 500);
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            word[j] = '\0';
            changeOrder(word, 0);
            cout << " ";
            j = 0;
        }
        else
        {
            word[j]= str[i];    
            j++;
        }
    }
    word[j] = '\0';
    changeOrder(word, 0);
    cout << endl;
    return 0;
}