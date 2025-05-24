// add 2 num
// max of 3 num
// student  and grade 
// convert km to miles
// convert celsius to fahrenheit


#include <iostream>
using namespace std;

int add(int a,int b)
{ 
    int sum=a+b;
    cout<<sum;
    return 0;
}

int max(int a,int b,int c)
{
    if(a>b && a>c)
    {
        cout<<a<<" is maximum number";
    }
    else if(b>a && b>c)
    {
        cout<<b<<" is maximum number";
    }
    else{
        cout<<c<<" is maximum number";
    }
    return 0;
}

int Grade(int m)
{
    if(m>90 && m<=100)
    {
        cout<<"A";
    }
    else if(m>70)
    {
        cout<<"B";
    }
    else if(m>60)
    {
        cout<<"C";
    }
    else if(m>40)
    {
        cout<<"D";
    }
    else{
        cout<<"F";
    }
    return 0;
}

int kmToMiles(int km)
{
    double miles=0.62137*km;
    cout<<km<<" is equal to "<<miles<<" miles";
}

int temp(int celsius)
{
    double F=((9*celsius)/5)+32;
    cout<<"Fahrenheit:"<<F;  
}

int main()
{
    int n,a,b,c,marks,km,celsius;  

    cout<<"Enter\n 1.Add two numbers \n 2.Maximum of three numbers \n 3.Grade of marks \n 4.Convert Kilometers to Miles \n 5.Convert Celsius to Fahrenheit"<<endl;

    cin>>n;

    switch (n)
    {
    case 1:cout<<"Enter two numbers:";
           cin>>a;
           cin>>b;
           add(a,b);
        break;

    case 2:cout<<"Enter three number:";
           cin>>a;
           cin>>b;
           cin>>c;
           max(a,b,c);
        break;

    case 3:cout<<"Enter marks:";
           cin>>marks;
           Grade(marks);
        break;

    case 4:cout<<"Enter Distance:";
           cin>>km;
           kmToMiles(km);
        break;

    case 5:cout<<"Enter Temperature:";
           cin>>celsius;
           temp(celsius);
        break;
    
    default:cout<<"Invalid entry";
        break;
    }

} 
