#include <iostream>
using namespace std;

const int MAXN = 100; // Maximum number of vertices in the graph

int graph[MAXN][MAXN]; // The graph
int maxClique[MAXN]; // Array to store the maximum clique found so far
int maxCliqueSize = 0; // Variable to store the size of the maximum clique

// Function to check if a vertex can be added to the current clique
bool isSafe(int v, int clique[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (graph[v][clique[i]] == 0)
            return false;
    }
    return true;
}

// Function to find the maximum clique using backtracking
void findMaxClique(int clique[], int size, int v, int n)
{
    // Base case: all vertices have been processed
    if (v == n)
    {
        if (size > maxCliqueSize)
        {
            maxCliqueSize = size;
            for (int i = 0; i < size; i++)
                maxClique[i] = clique[i];
        }
        return;
    }

    // Try adding the current vertex to the clique
    if (isSafe(v, clique, size))
    {
        clique[size] = v;
        findMaxClique(clique, size + 1, v + 1, n);
    }

    // Try not adding the current vertex to the clique
    findMaxClique(clique, size, v + 1, n);
}

int main()
{
    int n; // Number of vertices in the graph
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    // Input the graph
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int clique[MAXN]; // Array to store the current clique being constructed

    // Find the maximum clique using backtracking
    findMaxClique(clique, 0, 0, n);

    // Output the maximum clique
    cout << "The maximum clique is of size " << maxCliqueSize << " and contains the following vertices: ";
    for (int i = 0; i < maxCliqueSize; i++)
        cout << maxClique[i] << " ";
    cout << endl;

    return 0;
}