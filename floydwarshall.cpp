//ALL PAIR SHORTEST PATH

#include <iostream>
#include <limits.h>
using namespace std;
int arr[20][20];

void GenPath( )
{
    
}

int main()
{
    int v, e;
    cin>>v>>e;

    for(int i = 1; i<=v; i++)
    {
        for(int j = 1; j<=v; j++)
        {
            arr[i][j] = INT_MAX;
        }
    }

    for(int i = 1; i<=e; i++)
    {
        int u, v1, s;
        cin>>u>>v1>>s;
        arr[u][v1] = s;
        arr[v1][u] = s;
    }
}