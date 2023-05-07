#include<iostream>
using namespace std;

const int INF = 1e9;

int n, m;         // n = number of vertices, m = number of edges
int adj[10][10];  // adjacency matrix
int dist[10];     // stores the minimum distance from MST for each vertex
int parent[10];   // stores the parent of each vertex in the MST
bool vis[10];     // visited array to keep track of processed vertices

int prim()
{
    // initialization
    for(int i=0; i<n; i++)
    {
        dist[i] = INF;
        vis[i] = false;
        parent[i] = -1;
    }
    dist[0] = 0;

    // main loop
    for(int i=0; i<n; i++)
    {
        int u = -1;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && (u==-1 || dist[j]<dist[u]))
            {
                u = j;
            }
        }

        vis[u] = true;

        for(int v=0; v<n; v++)
        {
            if(!vis[v] && adj[u][v]<dist[v])
            {
                dist[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += dist[i];
    }
    return ans;
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adj[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int ans = prim();
    cout<<"Total weight of the MST: "<<ans<<endl;

    cout<<"Order of vertices in the MST:"<<endl;
    for(int i=1; i<n; i++)
    {
        cout<<i+1<<" - "<<parent[i]+1<<endl;
    }

    return 0;
}