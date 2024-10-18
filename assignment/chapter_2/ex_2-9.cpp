#include <iostream>
using namespace std;

double MEAN(double A, double B, double C)
{
    double AVE = (A + B + C) / 3;

    return AVE;
}

int main()
{
    double T1, T2, T3;
    cout << "Enter three test scores: ";
    cin >> T1 >> T2 >> T3;

    double TEST = MEAN(T1, T2, T3);

    cout << "The average of the three test scores is: " << TEST << endl;

    return 0;
}
