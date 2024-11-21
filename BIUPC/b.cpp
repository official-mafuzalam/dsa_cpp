#include <iostream>
using namespace std;

int main()
{
    long long candies;

    cin >> candies;

    if (candies % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
