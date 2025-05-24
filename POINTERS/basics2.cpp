#include <iostream>
using namespace std;

int update(int* p)
{
    *p=*p+10;
    cout<<"inside"<<*p<<endl;
}
int main(){


    int a=5;
    int* ptr=&a;
    update(ptr);
    cout<<*ptr;
    // char name[10]="srajan";
    // char* c=&name[0];

    // cout<<name<<endl;
    // cout<<&name<<endl;
    // cout<<*(name+3)<<endl;
    // cout<<c<<endl;
    // cout<<&c<<endl;
    // cout<<*(c+3)<<endl;
    // cout<<c+2<<endl;
    // cout<<*c<<endl;
    // cout<<c+4<<endl;


    // int a=5;
    // int* p=&a;
    // cout<<p<<endl;

    // char ch[7]="srajan";
    // char* c=ch;
    // cout<<c<<endl;
    // cout<<*c;

    // int arr[4] = {12,44,66,18};
    // cout<<arr<<endl;
    // cout<<arr[0]<<endl;
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;


    // int* p=arr;
    // cout<<p<<endl;
    // cout<<&p<<endl;

    // cout<<*arr<<endl;
    // cout<<arr[0]<<endl;
    // cout<<*arr+1<<endl;
    // cout<<*(arr)+1<<endl;
    // cout<<*(arr+1)<<endl;
    // cout<<arr[1]<<endl;
    // cout<<*(arr+2)<<endl;
    // cout<<arr[2]<<endl;
    // cout<<*(arr+3)<<endl;
    // cout<<arr[3]<<endl;    
    return 0;
}