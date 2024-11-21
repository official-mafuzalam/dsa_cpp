#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> dis(n);
        vector<int> rIndices;

        for (int i = 0; i < n; i++) {
            cin >> dis[i];
            if (dis[i] > d) {
                rIndices.push_back(i + 1);
            }
        }

        if (rIndices.empty()) {
            cout << "FE!N" << endl;
        } else {
            cout << rIndices.size() << endl;
            for (int idx : rIndices) {
                cout << idx << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
