#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cctype>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

    vector<int> buildPath(int target, vector<int>& parent) {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    void dfsRekursif(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << char('A' + u) << " ";

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] != 0 && !visited[v]) {
                dfsRekursif(v, visited);
            }
        }
    }

public:
    Graph(int jumlahVertex) {
        V = jumlahVertex;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void printAdjMatrix() {
        cout << "   ";
        for (int i = 0; i < V; i++) cout << char('A' + i) << "  ";
        cout << endl;
        for (int i = 0; i < V; i++) {
            cout << char('A' + i) << "  ";
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS dari " << char('A' + start) << " : ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << char('A' + u) << " ";

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        cout << "DFS dari " << char('A' + start) << " : ";
        dfsRekursif(start, visited);
        cout << endl;
    }

    void dijkstra(int src, int dest) {
        vector<int> distance(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);
        distance[src] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX) break;
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "Jarak terpendek dari " << char('A' + src) << " ke " << char('A' + dest) << endl;

        if (distance[dest] == INT_MAX) {
            cout << "Tidak ada rute yang tersedia." << endl;
            return;
        }

        vector<int> path = buildPath(dest, parent);
        cout << "Rute        : ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << char('A' + path[i]);
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Total jarak : " << distance[dest] << endl;
    }
};

int main() {
    Graph graph(6);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2); 
    graph.addEdge(1, 2, 1); 
    graph.addEdge(1, 3, 5); 
    graph.addEdge(1, 4, 3); 
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 6); 
    graph.addEdge(3, 4, 2); 
    graph.addEdge(3, 5, 4); 
    graph.addEdge(4, 5, 3); 

    cout << "Adjacency Matrix:" << endl;
    graph.printAdjMatrix();
    cout << endl;

    char asal, tujuan;
    cout << "Masukkan vertex awal (A-F)   : ";
    cin >> asal;
    cout << "Masukkan vertex tujuan (A-F) : ";
    cin >> tujuan;

    int s = toupper(asal) - 'A';
    int d = toupper(tujuan) - 'A';

    if (s < 0 || s >= 6 || d < 0 || d >= 6) {
        cout << "Vertex tidak valid!" << endl;
        return 0;
    }

    cout << endl;
    graph.bfs(s);
    graph.dfs(s);
    cout << endl;
    graph.dijkstra(s, d);

    return 0;
}
