#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, d;

    cout << "Enter value of A: ";
    cin >> a;

    cout << "Enter value of B: ";
    cin >> b;

    cout << "Enter value of C: ";
    cin >> c;

    d = pow(b, 2) - (4 * a * c);

    if (d > 0)
    {
        float x1 = (-b + sqrt(d)) / (2 * a);
        float x2 = (-b - sqrt(d)) / (2 * a);

        cout << "X1 and X2 is: " << x1 << endl
             << x2;
    }
    else if (d = 0)
    {
        float x = -b / (2 * a);
        cout << "UNIQUE SOLUTION: " << x << endl;
    }
    else
    {
        cout << "NO REAL SOLUTIONS";
    }

    return 0;
}
