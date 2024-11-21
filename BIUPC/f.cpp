#include <iostream>
using namespace std;

long long get_xor(long long k) {
    if (k % 4 == 0) return k;
    if (k % 4 == 1) return 1;
    if (k % 4 == 2) return k + 1;
    return 0;
}

long long func(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n; ++i) {
        sum += get_xor(i);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        cout << func(n) << endl;
    }

    return 0;
}
