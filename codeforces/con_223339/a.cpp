#include <iostream>
using namespace std;

void recursion(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << "I Love Recursion" << endl;
        recursion(n - 1);
    }
}

int main()
{
    recursion(5);

    return 0;
}
