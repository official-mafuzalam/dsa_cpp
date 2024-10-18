#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> DATA = {7, 12, 5, 20, 10};
    int N = DATA.size();

    int K = 1;
    int LOC = 1;
    int MAX = DATA[0];

    while (K < N) {
        K++; 
        if (MAX < DATA[K - 1]) { 
            LOC = K;    
            MAX = DATA[K - 1];
        }
    }

    cout << "The largest element is " << MAX << " at position " << LOC << endl;

    return 0;
}
