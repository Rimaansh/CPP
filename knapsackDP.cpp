#include <iostream>
using namespace std;

int w[100], v[100];
int DP[100][100];

int knapsack(int CAP, int n) 
{
   int i, wt;
   int DP[n + 1][CAP + 1]; //taking +1 cuz first row and column is 0
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= CAP; wt++) {
         if (i == 0 || wt == 0)
            DP[i][wt] = 0; //setting first row and column to 0
         else if (w[i - 1] <= wt) //weight of current less than max weight of column
            DP[i][wt] = max(v[i - 1] + DP[i - 1][wt - w[i - 1]], DP[i - 1][wt]);
         else
            DP[i][wt] = DP[i - 1][wt];
      }
   }
   return DP[n][CAP];
}

// int knapsack(int n, int W)
// {
//     if(W<=0) return 0;

//     if(n<=0) return 0;

//     if(dp[n][W] != -1) return dp[n][W];

//     if(wt[n-1]>W)
//     {
//         dp[n][W] = knapsack(n-1,  W);
//     }      
//     else
//     {
//         dp[n][W] = max(knapsack(n-1, W), knapsack(n-1, W - wt[n-1] + val[n-1]));
//     }        

//     return dp[n][W];
// }

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