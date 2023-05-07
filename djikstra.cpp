#include <iostream>
#include <vector>
using namespace std;

void djikstra(int** mat, int v, int src)
{
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);

    dist[src] = 0; //distance of a vertex from itself is 0

    for(int i = 1; i<=v; i++)
    {
        
    }
}

int main()
{
    cout<<"Enter the number of vertices and edges"<<endl;
    int v, e;
    cin>>v>>e;
    int mat[v+1][v+1];
    for(int i = 1; i<=v; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            mat[i][j] = 0;
        }
    }     

    for(int i = 1; i<=e; i++)
    {
        cout<<"Enter vertices of an edge and distance"<<endl;
        int u, v, dist;
        cin>>u>>v>>dist;
        mat[u][v] = dist;
    }       

    cout<<"Enter source vertex - ";
    cin>>src;
    djikstra(mat, v, src);
}