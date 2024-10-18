#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> DATA = {7, 12, 5, 20, 10};
    int N = DATA.size();

    int K = 1;
    int LOC = 1;
    int MAX = DATA[0];

    while (K < N)
    {
        if (MAX < DATA[K])
        {
            LOC = K + 1;
            MAX = DATA[K];
        }
        K++;
    }

    cout << "The largest element is " << MAX << " at position " << LOC << endl;

    return 0;
}
