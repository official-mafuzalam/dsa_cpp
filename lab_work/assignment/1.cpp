#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[v];
        for (int i = 0; i < v; i++) {
            adjMatrix[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        cout << "Edge added: (" << u << ", " << v << ")" << endl;
    }

    void BFS(int start) {
        bool* visited = new bool[vertices]; 
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; 
        }

        int* queue = new int[vertices];
        int front = 0, rear = 0;     

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS Traversal starting from vertex " << start << ": ";

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true; 
                    queue[rear++] = i; 
                }
            }
        }
        cout << endl;

        delete[] visited;
        delete[] queue;
    }
};

int main() {
    Graph g(6);

    cout << "Adding edges to the graph:" << endl;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << endl;

    g.BFS(0);

    return 0;
}