// factorial of num
// print prime num from 1 to n
// counting from 1 to n
// sum of even no upto n
// sum of odd no upto n
// print all digits in integer


#include <iostream>
#include <vector>
using namespace std;

int factorial(int num)
{
    int fact = 1;

    if(num==0 || num==1){
     fact=1;
    }

    if(num<0)
    {
        cout<<"Factorial cant be find";
    }

    for(int i=num;i>1;i--)
    {
        fact=fact*i;
    }

    cout<<"FACTORIAL = "<<fact<<endl;
}

int printPrime(int num)
{
    vector<int> arr = {1};
    for(int i=2;i<=num;i++)
    {
        int c=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        }

        if(c==2)
        {
            arr.push_back(i);            
        }
    }
    for (int i : arr) {
        cout << i << " ";
    }
}

int counting(int num)
{
    for(int i=1;i<=num;i++)
    {
        cout<<i<<" ";
    }
}

int sumEven(int num)
{
    int sum=0;
    for(int i=1;i<=num;i++)
    {
        if(i%2==0)
        {
            sum=sum+i;
        }
    }
    cout<<sum;
}

int sumOdd(int num)
{
    int sum=0;
    for(int i=1;i<=num;i++)
    {
        if(i%2!=0)
        {
            sum=sum+i;
        }
    }
    cout<<sum;
}

int digitsOfInteger(int num)
{
    while (num!=0)
    {
        int a=num%10;
        cout<<a<<" ";
        num=num/10;
    }
}

int main()
{
    int n,num;

    cout<<"Enter\n 1.Factorial of Number \n 2.Print prime numbers from 1 to n \n 3.counting from 1 to n \n 4.Print sum of even integers from 1 to n \n 5.Print sum of odd integers from 1 to n \n 6.Print all integer of a digit"<<endl;

    cin>>n;

    switch (n)
    {
    case 1:cout<<"Enter a number:";
           cin>>num;
           factorial(num);
        break;

    case 2:cout<<"Enter a number:";
           cin>>num;
           printPrime(num);
        break;

    case 3:cout<<"Enter a number:";
           cin>>num;
           counting(num);
        break;

    case 4:cout<<"Enter a number:";
           cin>>num;
           sumEven(num);
        break;

    case 5:cout<<"Enter a number:";
           cin>>num;
           sumOdd(num);
        break;

    case 6:cout<<"Enter a number:";
           cin>>num;
           digitsOfInteger(num);
        break;
    
    default:cout<<"Invalid entry";
        break;
    }

}