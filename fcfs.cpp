#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout<<"Enter request queue size and values - "<<endl;
    int n, sum = 0, head;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter header - "<<endl;
    cin>>head;

    vector<pair<int, int> > track (n);
    pair<int, int> t;
    t.first = head;
    t.second = arr[0];
    
    sum+= abs(t.first - t.second);

    for(int i = 0; i<n-1; i++)
    {
        pair<int, int> temp;
        temp.first = arr[i];
        temp.second = arr[i+1];
        track.push_back(temp);
    }

    for(pair<int, int> num: track)
    {
        sum+= abs(num.first - num.second);
    }

    cout<<sum<<endl;
    return 0;
}
