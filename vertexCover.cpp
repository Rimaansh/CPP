#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to find the vertex cover of minimum size
void findMinVertexCover(int V, vector<pair<int, int>> edges) {
    set<int> vertexCover;

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // If neither u nor v is in the vertex cover, add both
        if (vertexCover.find(u) == vertexCover.end() && vertexCover.find(v) == vertexCover.end()) {
            vertexCover.insert(u);
            vertexCover.insert(v);
        }
    }

    // Print the size and contents of the minimum vertex cover
    cout << "Size of minimum vertex cover: " << vertexCover.size() << endl;
    cout << "Vertices in minimum vertex cover: ";
    for (auto vertex : vertexCover) {
        cout << vertex << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int V, E; // Number of vertices and edges in the graph
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> V >> E;

    vector<pair<int, int>> edges(E);
    cout << "Enter the edges of the graph (u v): " << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    findMinVertexCover(V, edges);

    return 0;
}