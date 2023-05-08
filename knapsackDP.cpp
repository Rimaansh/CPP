#include <iostream>
using namespace std;

int w[100], v[100];
int DP[100][100];

int knapsack(int capacity, int n) 
{
   int i, wt;
   //int DP[n + 1][capacity + 1]; //taking +1 cuz first row and column is 0
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= capacity; wt++) {
         if (i == 0 || wt == 0)
            DP[i][wt] = 0; //setting first row and column to 0
         else if (w[i - 1] <= wt) //weight of current less than max weight of column
            DP[i][wt] = max(v[i - 1] + DP[i - 1][wt - w[i - 1]], DP[i - 1][wt]);
         else
            DP[i][wt] = DP[i - 1][wt];
      }
   }
   return DP[n][capacity];
}

int main()
{
    int n, W;
    cin>>n>>W;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            DP[i][j] = -1;
        }
    }

    for(int i = 0; i<n; i++) cin>>w[i];

    for(int i = 0; i<n; i++) cin>>v[i];

    cout<<knapsack(W, n)<<endl;
}