#include <iostream>
#include <vector>
using namespace std;

void printDigits(int n)
{
    if(n==0)
    return ;

    int num=n/10; 
    printDigits(num);
    int digit=n%10;
    cout<<digit<<" "; 
}

int main()
{
    int n=647;
    printDigits(n);
}