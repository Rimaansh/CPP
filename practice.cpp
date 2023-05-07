#include <iostream>
using namespace std;

int graph[20][20];
int maxCliqueSize = 0;
int clique[20], maxClique[20];

bool isSafe(int v, int* clique, int size)
{
    for(int i = 0; i<size; i++)
    {
        if(graph[i][clique[i]] == 0) return false;
    }
    return true;
}

void findMaxClique(int clique[], int size, int v, int n)
{
    if(v == n)
    {
        if(size > maxCliqueSize)
        {
            maxCliqueSize = size;
            for(int i = 0; i<n; i++) maxClique[i] = clique[i];
        }
        return;
    }

    if(isSafe(v, clique, size))
    {
        clique[size] = v;
        findMaxClique(clique, size, v+1, n);
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int clique[20];
    findMaxClique(clique, 0, 0, n);

    cout << "The maximum clique is of size " << maxCliqueSize << " and contains the following vertices: ";
    for (int i = 0; i < maxCliqueSize; i++)
        cout << maxClique[i] << " ";
    cout << endl;

    return 0;
}