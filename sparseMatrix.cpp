#include <iostream>
using namespace std;

class sparse
{
    public:
        int row, col, val;

        sparse()
        {
            row = 0;
            col = 0;
            val = 0;
        }

        sparse(int r, int c, int v)
        {
            row = r;
            col = c;
            val = v;
        }

};

void FTranspose(sparse s[], int nonzero)
{
    for(int i = 0; i<nonzero; i++)
    {
        int temp = s[i].row;
        s[i].row = s[i].col;
        s[i].col = temp;
    }
}

int main()
{
    cout<<"Enter no of rows and cols"<<endl;
    int m, n, nonzero = 0;
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter nos"<<endl;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] != 0) nonzero++;
        }
    }

    sparse s[nonzero];

    int i = 0;
    for(int j = 0; j<m; j++)
    {
        for(int k = 0; k<n; k++)
        {
            if(arr[j][k] != 0)
            {
                s[i].row = j;
                s[i].col = k;
                s[i].val = arr[j][k];

                i++;
            }
        }
    }

    cout<<"ROW \t COLUMN \t VALUE"<<endl;
    for(int i = 0; i<nonzero; i++)
    {
        cout<<s[i].row<<"\t\t"<<s[i].col<<"\t\t"<<s[i].val<<"\t\t"<<endl;
    }

    FTranspose(s, nonzero);

    cout<<"\nROW \t COLUMN \t VALUE"<<endl;
    for(int i = 0; i<nonzero; i++)
    {
        cout<<s[i].row<<"\t\t"<<s[i].col<<"\t\t"<<s[i].val<<"\t\t"<<endl;
    }

    return 0;
}
