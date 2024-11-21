#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of rings in the current test case
        cin >> n;

        vector<int> rings(n);
        for (int i = 0; i < n; i++) {
            cin >> rings[i];
        }

        multiset<int> towers; // Store the top elements of towers

        for (int i = 0; i < n; i++) {
            auto it = towers.upper_bound(rings[i]); // Find the smallest top > current ring
            if (it != towers.end()) {
                towers.erase(it); // Replace the top of this tower
            }
            towers.insert(rings[i]); // Add current ring to a new or existing tower
        }

        cout << towers.size() << endl; // Print the number of towers needed
    }

    return 0;
}
