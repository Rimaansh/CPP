#include <iostream>
#include <vector>
using namespace std;

void addSol(vector<vector<int> > &board, vector<vector<int> > &ans, int n)
{
    vector<int> temp;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int> > &board)
{
    int x = row, y = col;
    //checking for same row
    while(y >= 0){
        if(board[x][y] == 1) return false;
        y--;
    }

    x = row, y = col;
    //checking upper diagonal (row-1, col-1)
    while(x>=0 && y >= 0){
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }

    x = row, y = col;
    //checking upper diagonal (row+1, col-1)
    while(x>=0 && y >= 0){
        if(board[x][y] == 1) return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int> > &ans, vector<vector<int> > &board, int n)
{
    //base case
    if(col == n) {
        addSol(board, ans, n);
        return;
    }

    for(int row = 0; row<n; row++)
    {
        if(isSafe(row, col, board)) //if placing on row-col is safe
        {
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            //backtrack now
            board[row][col] = 0;
        }
    }
}

vector<vector<int> > nQueens(int n)
{
    vector<vector<int> > board(n, vector<int>(n, 0));
    vector<vector<int> > ans;

    solve(0, ans, board, n); //0 is column no

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > vec = nQueens(n);

    for (int i = 0; i < vec.size(); i++) {
    for (auto it = vec[i].begin(); it != vec[i].end(); it++)
        cout << *it << " ";
        cout << endl;
    }
}
