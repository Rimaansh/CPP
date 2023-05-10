#include<iostream>
using namespace std;

int maximum[10][10],allocation[10][10],need[10][10];
int avail[10];
int np,nr;

void readmatrix(int matrix[10][10])
{
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            cin>>matrix[i][j];       
        }
    }
}

void displaymatrix(int matrix[10][10])
{
    for(int i=0;i<np;i++)
    {
        for(int j=0;j<nr;j++)
        {
            cout<<matrix[i][j]<<" ";       
        }
        cout<<endl;
    }

}

void calculate_need()
{
    for(int i=0;i<np;i++)
    {
        for(int j=0;j<nr;j++)
        {
            need[i][j]=maximum[i][j]-allocation[i][j];
        }
    }
}

void banker()
{
    int finish[10],safe_seq[10];
    int flag;
    int k=0;
    for(int i=0;i<np;i++)
    {
        finish[i]=0;//declaring al processes incomplete
    }
    for(int i=0;i<np;i++)
    {
        flag=0;
        if(finish[i]==0)
        {//execute incomplete process 
            for(int j=0;j<nr;j++)
            {
                if(need[i][j]>avail[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                finish[i]=1;
                safe_seq[k]=i;
                k++;
                for(int j=0;j<nr;j++)
                {
                    avail[j]+=allocation[i][j];
                }
                i=-1;
            }
        }
    }
    flag=0;
    for(int i=0;i<np;i++)
    {
        if(finish[i]==0)
        {
            cout<<"system in deadlock"<<endl;

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"the system is in a safe state"<<endl;
        for(int i=0;i<np;i++){
            cout<<"P"<<safe_seq[i]<<" ";
        }
    }
}

int main()
{
    cout<<"enter number of processes: "<<endl;
    cin>>np;
    cout<<"enter number of resources: "<<endl;
    cin>>nr;
    cout<<endl<<"enter allocation matrix"<<endl;
    readmatrix(allocation);
    cout<<endl<<"enter max matrix"<<endl;
    readmatrix(maximum);
    cout<<"enter avl resources: "<<endl;

    for(int j=0;j<nr;j++)
    {
        cin>>avail[j];
    }

    cout<<endl<<endl<<"entered data is "<<endl<<endl;
    cout<<"allocation matrix"<<endl<<endl;
    displaymatrix(allocation);
    cout<<endl<<endl<<"maximum matrix"<<endl<<endl;
    displaymatrix(maximum);
    cout<<endl<<endl<<"entered avl resources";

    for(int i=0;i<nr;i++)
    {
        cout<<avail[i]<<" ";
    }
    cout<<endl<<endl;
    calculate_need();
    cout<<endl<<endl<<"need matrix is: "<<endl;
    displaymatrix(need);
    cout<<endl<<endl;
    banker();
    cout<<endl<<endl;
    return 0;
}

/*
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/
