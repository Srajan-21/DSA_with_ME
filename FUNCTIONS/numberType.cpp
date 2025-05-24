#include <iostream>
using namespace std;

int oddEven(int num)
{
    if(num%2==0)
    {
        cout<<"EVEN";
    }
    else
    {
        cout<<"ODD";
    }

    return 0;
}

int Prime(int num)
{
    int count=0;
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            count++;
        }
    }

    if(count==2)
    {
        cout<<"PRIME";
    }
    else
    {
        cout<<"NOT PRIME";
    }

    return 0;
}

int main(){
    int num;
    int n;

    cout<<"Enter choice 1.ODD/EVEN 2.PRIME => ";
    cin>>n;

    switch(n)
    {
        case 1: cout<<"Enter a number:";
                cin>>num;
                oddEven(num);
                break;

        case 2: cout<<"Enter a numbeer:";
                cin>>num;
                Prime(num);
                break;

        default: cout<<"Invalid Entry";
    }
    return 0;
}