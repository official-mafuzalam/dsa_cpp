#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double A, B, C;
    cout << "Enter coefficients A, B, and C: ";
    cin >> A >> B >> C;

    double D = B * B - 4 * A * C;

    if (D > 0)
    {
        double X1 = (-B + sqrt(D)) / (2 * A);
        double X2 = (-B - sqrt(D)) / (2 * A);
        cout << "Two real solutions: X1 = " << X1 << " and X2 = " << X2 << endl;
    }
    else if (D == 0)
    {
        double X = -B / (2 * A);
        cout << "Unique solution: X = " << X << endl;
    }
    else
    {
        cout << "No real solutions." << endl;
    }

    return 0;
}
