#include <iostream>
#include <math.h>
using namespace std;

int countDigit(int n)
{
    int c = 0;
    while(n>0)
    {
        n/=10;
        c++;
    }
    return c;
}
    
int decToBin(int n)
{
    int bin = 0, d, flag = 0, c = 0, hund = 1;
    while(n>0)
    {
        d = n%2;
        if(d == 1) flag = 1;

        if(!flag) hund*=10;
        bin = bin*10+d;
        n/=2;
    }

    return bin*hund;
}

int binToDec (int n)
{
    int c = 0, dec = 0, d;
    while(n>0)
    {
        d = n % 10;
        n /=10;
        dec = dec + (int)(pow(2, c)*d);
        c++;
    }
    return dec;
}

int bitwiseComplement(int n) 
{
    int ones = 1, comp;
    int bin = decToBin(n);
    int c = countDigit(bin);
    for(int i = 0; i<c-1; i++) ones= ones*10 + 1;
    comp = ones - bin;
    int newDec = binToDec(comp);
    return newDec;
}

int main()
{
    int n;
    cin>>n;
    cout<<bitwiseComplement(n)<<endl;
}