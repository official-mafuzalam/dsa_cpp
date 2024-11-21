#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int totalCount = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    totalCount += dp[i][j];
                }
            }
        }
        cout << "Case " << test_case << ": " << totalCount << endl;
    }

    return 0;
}
