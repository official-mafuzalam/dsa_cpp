#include <iostream>
using namespace std;

int main()
{
    int N;

    // Input size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    // Declare array
    int DATA[N];

    // Input array elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> DATA[i];
    }

    // Step 1: Initialize
    int K = 1;
    int LOC = 0;       // Location of largest element (0-based index)
    int MAX = DATA[0]; // Assume the first element is the largest

    // Step 2: Increment counter and loop through the array
    while (K < N)
    {
        // Step 4: Compare and update
        if (MAX < DATA[K])
        {
            LOC = K;
            MAX = DATA[K];
        }
        // Step 2: Increment counter
        K++;
    }

    // Step 3: Output the results
    cout << "Location of largest element (0-based index): " << LOC << endl;
    cout << "Value of largest element: " << MAX << endl;

    return 0;
}
