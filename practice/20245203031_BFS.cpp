#include <iostream>
using namespace std;

const int MAX = 100;

// ----------------------------
// Queue class implementation
// ----------------------------
class Queue {
    int arr[MAX];     // Array to store elements
    int front, rear;  // Indices for front and rear
public:
    Queue() { front = rear = -1; } // Initialize both as empty

    bool isEmpty() { return front == -1; } // Check empty condition
    bool isFull() { return (rear + 1) % MAX == front; } // Circular full check

    // Enqueue adds element at rear
    void enqueue(int val) {
        if (isFull()) { cout << "Queue is full\n"; return; }
        if (isEmpty()) { front = rear = 0; } 
        else { rear = (rear + 1) % MAX; }
        arr[rear] = val;
    }

    // Dequeue removes element from front
    int dequeue() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        int val = arr[front];
        if (front == rear) front = rear = -1; // Queue becomes empty
        else front = (front + 1) % MAX;
        return val;
    }
};

// ----------------------------
// Input adjacency matrix
// ----------------------------
void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e) {
    // Initialize adjacency matrix with zeros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;  // Directed edge u → v
            adj[v][u] = 1;  // Uncomment for undirected graph (kept for example)
        } else {
            cout << "Invalid nodes. Try again.\n";
            i--;
        }
    }
}

// ----------------------------
// Print adjacency matrix
// ----------------------------
void printAdjMatrix(int adj[MAX][MAX], int n) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

// ----------------------------
// BFS algorithm implementation
// ----------------------------
void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX]; // Track visited nodes
    for (int i = 0; i < n; i++)
        visited[i] = 0; // Initially all unvisited

    Queue q;           // Create queue
    visited[start] = 1; // Mark start as visited
    q.enqueue(start);   // Enqueue start node

    cout << "\nBFS Traversal starting from node " << start << ":\n";

    // Loop while queue not empty
    while (!q.isEmpty()) {
        int current = q.dequeue(); // Get front element
        cout << current << " ";    // Print it (BFS visit order)

        // Explore all neighbors of 'current'
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) { // If edge exists and not visited
                visited[i] = 1; // Mark visited
                q.enqueue(i);   // Enqueue neighbor
            }
        }
    }
    cout << endl;
}

// ----------------------------
// Main function
// ----------------------------
int main() {
    int n, e;
    int adj[MAX][MAX];

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    inputEdgesToAdjMatrix(adj, n, e); // Input edges
    printAdjMatrix(adj, n);           // Print adjacency matrix

    int start;
    cout << "Enter start node: ";
    cin >> start;

    BFS(adj, n, start); // Perform BFS

    return 0;
}
