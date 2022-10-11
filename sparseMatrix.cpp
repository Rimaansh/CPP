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

void FTranspose(sparse a[], sparse b[])
{
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    int n = a[0].val;
    int curr = 1;

    for(int i = 0; a[0].col; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            if(a[j].col == i)
            {
                b[curr].row = a[j].row;
                b[curr].col = a[j].col;
                b[curr++].val = a[j].val;
            }
        }
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

    sparse s[nonzero], trans[nonzero];

    int i = 0;

    s[0].row = m;
    s[0].col = n;
    s[0].val = nonzero;

    for(int j = 1; j<m; j++)
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
    for(int i = 0; i<=nonzero; i++)
    {
        cout<<s[i].row<<"\t\t"<<s[i].col<<"\t\t"<<s[i].val<<"\t\t"<<endl;
    }

    FTranspose(s, trans);

    cout<<"\nROW \t COLUMN \t VALUE"<<endl;
    for(int i = 0; i<=nonzero; i++)
    {
        cout<<trans[i].row<<"\t\t"<<trans[i].col<<"\t\t"<<trans[i].val<<"\t\t"<<endl;
    }

    return 0;̀
}
