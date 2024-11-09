#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> flowers(N);
        for (int i = 0; i < N; ++i) {
            cin >> flowers[i].first >> flowers[i].second;
        }

        int total_watering = 0;

        for (const auto& flower : flowers) {
            int X = flower.first;
            int Y = flower.second;

            // If the initial day (X) is greater than K, no need to water this flower at all
            if (X > K) continue;

            // Calculate the last day we can water this flower within the K-day period
            int remaining_days = K - X;

            // Calculate the number of times we need to water this flowerbed
            int waterings = 1 + (remaining_days / Y);

            // Add to total watering count
            total_watering += waterings;
        }

        cout << "Case " << t << ": " << total_watering << endl;
    }

    return 0;
}
