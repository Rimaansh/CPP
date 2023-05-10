#include <iostream>
#include <vector>
using namespace std;

void bestfit(vector<int>blocks, vector<int> processes){
    vector<int>allocation(processes.size(), -1);
    for(int i=0;i<processes.size();i++){
        int in = -1;
        for(int j=0 ; j<blocks.size(); i++){
            if(blocks[j] >= processes[i]){
                if(in==-1){
                    in = j;
                }
                else if(blocks[j]<blocks[in]){
                    in = j;
                }
            }
            if(in != -1){
                allocation[i] = in;
                blocks[in]-=processes[i];
            }
        }
    }
    for (int i = 0; i < processes.size(); i++)
    {
        cout<<i+1<<"\t"<<processes[i]<<"\t";
        if(allocation[i]!=-1)cout<<allocation[i]+1<<endl;
        else cout<<"Not allocated"<<endl;
    }
}

void worstfit(vector<int> blocks, vector<int> processes){
    vector<int>allocation(processes.size(), -1); //allocation maintained to see which block the process has been put in
    for(int i=0;i<processes.size();i++){
        int in = -1;
        for(int j=0;j<blocks.size();j++){
            if(blocks[j]>=processes[i]){
                if(in == -1) in=j;
                else if(blocks[j]>blocks[in]){
                    in = j;
                }
            }
        }
        if(in!=-1){
                allocation[i]=in;
                blocks[i]-=processes[i];
            }
    }
    for (int i = 0; i < processes.size(); i++)
    {
        cout<<i+1<<"\t"<<processes[i]<<"\t";
        if(allocation[i]!=-1)cout<<allocation[i]+1<<endl;
        else cout<<"Not allocated"<<endl;
    }
}
void firstfit(vector<int>b,vector<int>p){
    vector<int>allocation(p.size(),-1);
    for (int i = 0; i < p.size(); i++){
        for (int j = 0; j < b.size(); j++)
        {
            if(b[j]>=p[i]){
                allocation[i]=j;
                b[j]-=p[i];
                break;
            }
        }
 
    }
    for (int i = 0; i < p.size(); i++)
    {
        cout<<i+1<<"\t"<<p[i]<<"\t";
        if(allocation[i]!=-1)cout<<allocation[i]+1<<endl;
        else cout<<"Not allocated"<<endl;
    }
} 

int main() {
    // create vectors of memory blocks and processes
    vector<int> blocks, processes;
    
    blocks.push_back(100);
    blocks.push_back(500);
    blocks.push_back(200);
    blocks.push_back(300);
    blocks.push_back(600);

    processes.push_back(212);
    processes.push_back(417);
    processes.push_back(112);
    processes.push_back(426);

    // allocate memory using First Fit algorithm
    cout << "First Fit Algorithm:" << endl;
    firstfit(blocks, processes);

    // allocate memory using Best Fit algorithm
    cout << "Best Fit Algorithm:" << endl;
    bestfit(blocks, processes);

    // allocate memory using Worst Fit algorithm
    cout << "Worst Fit Algorithm:" << endl;
    worstfit(blocks, processes);

    return 0;
}