#include <iostream>
using namespace std;

int main(){
    // int a=5;
    // int b=6;
    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<sizeof(&a)<<endl;
    // cout<<&b<<endl;
    // return 0;

    int a=6;

    int* p=&a;
    int* q=p;

    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    cout<<*p/2<<endl;
    cout<<*q/2<<endl;


    // a=a+1;
    // p=p+1;
    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<p;

    // cout<<"Address of a:"<<&a<<endl;
    // cout<<"Value stored at ptr:"<<ptr<<endl;
    // cout<<"value ptr is pointing at:"<<*ptr<<endl;
    // cout<<&ptr<<endl;
    return 0;



}