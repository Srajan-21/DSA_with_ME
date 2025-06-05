#include <iostream>
using namespace std;

class abc{
    int x;
    int *y;
    int z;

    public:
    // old style
    // abc(int _x,int _y,int -Z=0)
    // {
    //     x=_x;
    //     y=new int(_y);
    //     z=_z;
    // }

    // initialisation set
    abc(int _x,int _y,int _z=0):x(_x),y(new int (_y)),z(_z){}
    
};

int main()
{
    // const int x = 5; //x is constant
    // // initialisation can be done
    // // but we cant re-assign a value
    // // x=10; //error
    // cout<<x<<endl;

    // 2.const with pointer
    // const int *a = new int (2); // const data no const pointer
    // if we write const before * then content will be constant
    // int const *a = new int(2);
    // cout<<*a<<endl;
    // // *a=20; //error cant change content of pointer
    // int b=20;
    // a=&b; // pointer itself can be reassigned
    // cout<<*a<<endl;

    // 3. const poinyter non constant data
    // int *const a = new int (2);
    // cout<<*a<<endl;
    // *a=20; //no error
    // cout<<*a<<endl;
    // int b=40;
    // // a=&b; //error pointer constant

    // 4. const pointer const data
    // const int *const a = new int(10);
    // cout<<*a<<endl;
    // *a=20; //error
    // int b=100;
    // a=&b; //error

}