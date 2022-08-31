#include <iostream>
using namespace std;
#include <math.h>

int reverse(int x) 
{
    if(x<((int)pow(2, 31) - 1) && x>(-(int)pow(2, 31)))
    {  
        int unity = x<0? -1 : 1;
        x = (int)abs(x);
        int rev = 0, d;
        while(x>0)
        {
            d = x%10;
            rev = rev*10 + d;
            x/=10;
        }
        return unity*rev;

    } else {
        return 0;
    } 
}

int main()
{
    int n;
    cin >> n;
    cout << reverse(n);
}