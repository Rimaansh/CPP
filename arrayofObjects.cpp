#include <iostream>
using namespace std;

class SM
{
    public:
        int row, col, val;
};

int main()
{
    int m, n, i, j, k = 0, l, nonzero = 0, flag = 0;
    cout<<"Enter order of matrix"<<endl;
    cin>>m>>n;

    int arr[m][n];

    cout<<"Enter array elements"<<endl;
    for(i = 0; i<m; i++)
    {
        for(j = 0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(i = 0; i<m; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(arr[i][j]!=0) nonzero++;
        }
    }

    SM array[nonzero];

    for(i = 0; i<m; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(arr[i][j]!=0)
            {
                array[k].row = i;
                array[k].col = j;
                array[k].val = arr[i][j];
                k++;
            }
        }
    }
    
    cout<<"ROW \t COLUMN \t VALUE"<<endl;
    for(i = 0; i<nonzero; i++)
    {
        cout<<array[i].row<<"\t"<<array[i].col<<"\t"<<array[i].val;
        cout<<""<<endl;
    }

    cout<<"Enter search element"<<endl;
    int src;
    cin>>src;

    for(i = 0; i<nonzero; i++)
    {
        if(array[i].val == src)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        while(i<nonzero-1)
        {
            array[i]=array[i+1];
            i++;
        }

        cout<<"Modified array of objects"<<endl;
        cout<<"ROW \t COLUMN \t VALUE"<<endl;
        for(i = 0; i<nonzero-1; i++)
        {
            cout<<array[i].row<<"\t"<<array[i].col<<"\t"<<array[i].val;
            cout<<""<<endl;
        }

        cout<<""<<endl;
        cout<<"Modified array is"<<endl;

        for(i = 0; i<m; i++)
        {
            for(j = 0; j<n; j++)
            {
                arr[i][j] = 0;
            }
        }

        k = 0;
        for(i = 0; i<m; i++)
        {
            for(j = 0; j<n; j++)
            {
                if(array[k].row == i && array[k].col == j)
                {
                    arr[i][j] = array[k].val;
                    k++;
                }
            }
        }

        for(i = 0; i<m; i++)
        {
            for(j = 0; j<n; j++)
            {
                cout<<arr[i][j]<<"\t";
            }

            cout<<""<<endl;
        }
    }
    else
    {
        cout<<"Search Element Not Found"<<endl;
    }

    return 0;
}