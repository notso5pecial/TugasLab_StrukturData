#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int banyakTitik) {
            numberVertex = banyakTitik;
            adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
        }

        void addEdge(int i, int j) {
            if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            } else {
                cout << "Index nonvalid" << endl;
            }
        }

        void printAdjMatrix() {
            cout << "  ";
            for (int i = 0; i < numberVertex; i++) cout << char('A' + i) << " ";
            cout << endl;
            for (int i = 0; i < numberVertex; i++) {
                cout << char('A' + i) << " ";
                for (int j = 0; j < numberVertex; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void bfs(int startVertex) {
            vector<bool> visited(numberVertex, false);
            queue<int> titikVisit;

            visited[startVertex] = true;
            titikVisit.push(startVertex);

            cout << "Urutan BFS: ";
            while (!titikVisit.empty()) {
                int currentVertex = titikVisit.front();
                titikVisit.pop();
                cout << char('A' + currentVertex) << " ";

                for (int i = 0; i < numberVertex; i++) {
                    if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        titikVisit.push(i);
                    }
                }
            }
            cout << endl;
        }
};

int main() {
    Graph graphh(6); 

    int jumlahEdge;
    cout << "Masukkan jumlah edge: ";
    cin >> jumlahEdge;

    cout << "Masukkan edge (contoh: A B)" << endl;
    for (int k = 0; k < jumlahEdge; k++) {
        char a, b;
        cout << "Edge " << k + 1 << ": ";
        cin >> a >> b;
        graphh.addEdge(toupper(a) - 'A', toupper(b) - 'A');
    }

    cout << endl << "Adjacency Matrix:" << endl;
    graphh.printAdjMatrix();

    char start;
    cout << endl << "Masukkan vertex awal (A-F): ";
    cin >> start;
    int s = toupper(start) - 'A';

    if (s < 0 || s >= 6) {
        cout << "Vertex awal tidak valid!" << endl;
        return 0;
    }

    graphh.bfs(s);

    return 0;
}