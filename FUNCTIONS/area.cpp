#include <iostream>
#include <cmath>
using namespace std;


int area(int radius)
{
    double area = M_PI*radius*radius;
    cout<<"Area="<<area;
    return 0;
}

int square(int side)
{
    int area = side*side;
    cout<<"Area="<<area;
    return 0;
}

int rectangle(int length , int breadth)
{
    int  area = length*breadth;
    cout<<"Area="<<area;
    return 0;
}

int main(){
    
    int radius,side,length,breadth;
    int n;

    cout<<"Enter choice 1.Circle 2.Square 3.Rectangle => ";
    cin>>n;

    switch(n)
    {
        case 1: cout<<"Enter Radius of Circle:";
                cin>>radius;
                area(radius);
                break;

        case 2: cout<<"Enter Side of Square:";
                cin>>side;
                square(side);
                break;

        case 3: cout<<"Enter length of rectangle:";
                cin>>length;
                cout<<"Enter breadth of rectangle:";
                cin>>breadth;
                rectangle(length,breadth);
                break;

        default: cout<<"Invalid Entry";
    }
    return 0;
}