#include <iostream>
#include <cmath>
using namespace std;

int binaryToDcimal(int n)
{
    int decimal=0;
    int i=0;
    while(n>0)
    {
        int bit = n%10;
        decimal=decimal+bit*pow(2,i++);
        n/=10;
    }
    return decimal;
}

int decimalToBinary(int n)
{
    int binaryNo=0;
    int i=0;
    while(n>0)
    {
        int bit=n%2;
        binaryNo=bit*pow(10,i++)+binaryNo;
        n=n/2;
    }
    return binaryNo;
}

int main(){
    int n;
    cin>>n;
    int binary = decimalToBinary(n);
    cout<<binary<<endl;

    int m;
    cin>>m;
    int decimal = binaryToDcimal(m);
    cout<<decimal<<endl;
    return 0;
}