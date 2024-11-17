#include <iostream>
using namespace std;

int main()
{
    int w;
    cin >> w;

    if (w % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else if (w == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES";
    }

    return 0;
}
