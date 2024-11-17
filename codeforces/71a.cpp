#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int w;
    cin >> w;

    string word;

    for (int i = 0; i < w; i++)
    {
        cin >> word;
        int length = word.length();

        if (length > 10)
        {
            cout << word[0] << length - 2 << word[length - 1] << endl;
        }
        else
        {
            cout << word << endl;
        }
    }
    return 0;
}
