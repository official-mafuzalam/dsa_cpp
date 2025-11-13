#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 99999; // Large number representing infinity

// ----------------------------
// Input edges to adjacency matrix
// ----------------------------
void inputEdgesWeighted(int adj[MAX][MAX], int n, int e)
{
    // Initialize all distances as INF (no direct connection)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = (i == j) ? 0 : INF; // Distance to itself is 0

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= 0 && u < n && v >= 0 && v < n && w >= 0)
        {
            adj[u][v] = w; // Directed edge with weight
        }
        else
        {
            cout << "Invalid input. Try again.\n";
            i--;
        }
    }
}

// ----------------------------
// Dijkstra algorithm
// ----------------------------
void dijkstra(int adj[MAX][MAX], int n, int src)
{
    int dist[MAX];     // Distance array
    bool visited[MAX]; // Track visited vertices

    // Initialize distances and visited flags
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0; // Distance from source to itself is 0

    // Repeat n-1 times (each vertex processed once)
    for (int count = 0; count < n - 1; count++)
    {
        int minDist = INF, u = -1;

        // Pick the vertex with minimum distance not yet visited
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1)
            break; // All reachable nodes processed

        visited[u] = true; // Mark selected vertex as visited

        // Update distances of neighbors of u
        for (int v = 0; v < n; v++)
        {
            // Relaxation condition:
            if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print results
    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

// ----------------------------
// Main function
// ----------------------------
int main()
{
    int n, e;
    int adj[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    inputEdgesWeighted(adj, n, e);

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(adj, n, src);

    return 0;
}
