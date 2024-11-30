#include <iostream>
#include <cmath>
using namespace std;

string Powers_of_Two(int n)
{
    for (int i = 0; i < INT8_MAX; i++)
    {
        if (pow(2, i) == n)
        {
            return "True";
        }
        else if (pow(2, i) > n)
        {
            break;
        }
    }
    return "False";
}

int main()
{
    cout << "Is 8 a power of 2: " << Powers_of_Two(8) << endl;
    cout << "Is 256 a power of 2: " << Powers_of_Two(256) << endl;
    cout << "Is 124 a power of 2: " << Powers_of_Two(124) << endl;

    return 0;
}
