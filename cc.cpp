#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
	while(t-- > 0)
	{
	    int n, m, k, x;
	    cin>>n>>m>>k>>x;
	    int c = 1;
	    int sum = 0;
	    while(sum<=x)
	    {
	        c++;
	        if(c%k==0) sum+=(n+m);
	        else sum+=n;
	    }
	    
	    sum = 0;

	    int arr[c-1];
	    c = 0;
	    
	    while(sum<=x)
	    {
	        c++;
	        if(c%k==0) {
	            arr[c-1]=(n+m);
	            sum+=(n+m);
	        }
	        else {
	            arr[c-1]=n;
	            sum+=n;
	        }
	    }
	    cout<<c;
	    //
        for(int i = 0; i<c; i++) cout<<arr[i]<<endl;
	}
	return 0;
}
