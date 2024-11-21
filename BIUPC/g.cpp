#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];
int subtreeSize[MAXN];
int distanceFromAlice[MAXN];

// DFS to calculate subtree sizes
void calculateSubtreeSize(int node, int parent) {
    subtreeSize[node] = 1; // Count the current node
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            calculateSubtreeSize(neighbor, node);
            subtreeSize[node] += subtreeSize[neighbor];
        }
    }
}

// BFS to calculate distances from Alice's starting node
void calculateDistances(int start) {
    queue<int> q;
    q.push(start);
    distanceFromAlice[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : tree[node]) {
            if (distanceFromAlice[neighbor] == -1) {
                distanceFromAlice[neighbor] = distanceFromAlice[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // Precompute subtree sizes and distances
    fill(distanceFromAlice, distanceFromAlice + n + 1, -1);
    
    // Read number of queries
    int q;
    cin >> q;
    
    while (q--) {
        int aliceStart;
        cin >> aliceStart;
        
        // Step 1: Reset and calculate distances
        fill(distanceFromAlice, distanceFromAlice + n + 1, -1);
        calculateDistances(aliceStart);
        
        // Step 2: Calculate subtree sizes
        fill(subtreeSize, subtreeSize + n + 1, 0);
        calculateSubtreeSize(aliceStart, -1);
        
        // Step 3: Determine if Bob can start optimally
        bool bobCanWin = false;
        for (int i = 1; i <= n; ++i) {
            if (i != aliceStart && distanceFromAlice[i] > 0) {
                int bobSubtree = subtreeSize[i];
                int aliceSubtree = n - bobSubtree;
                
                if (bobSubtree > aliceSubtree) {
                    bobCanWin = true;
                    break;
                }
            }
        }
        
        if (bobCanWin)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
