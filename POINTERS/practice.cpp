#include <iostream>
using namespace std;

int main(){

    // example 1
    // float f=10.5;
    // float p=2.5;
    // float* ptr=&f;
    // (*ptr)++;
    // *ptr=p;
    // cout<<*ptr<<" "<<f<< " "<<p;

    // example 2
    // int a=7;
    // int b=17;
    // int *c=&b;
    // *c=7;
    // cout<<a<<" "<<b<<endl;

    // example 3
    // int* ptr=0;
    // int a=10;
    // *ptr=a;
    // cout<<*ptr;

    // exampl 4
    // char ch='a';
    // char* ptr=&ch;
    // ch++;
    // cout<<*ptr<<endl;

    // example 5
    // int a=7;
    // int *c=&a;
    // c=c+1;
    // cout<<a<<" "<<*c<<endl;

    // example 6
    // int a[]={1,2,3,4};
    // int *p=a++; runtime error
    // cout<<*p;

    // example 7 
    // char s[]="hello";
    // char *p=s;
    // cout<<s[0]<<" "<<p[0]<<" "<<p;

    // example 8
    // char *ptr; 
    // char str[]="abcdefgh";
    // ptr=str;
    // ptr+=5;
    // cout<<ptr;


    // example 9
    // char st[]="ABCD";
    // for(int i=0;st[i]!='\0';i++)
    // {
    //     cout<<st[i]<<*(st)+i<<*(i+st)<<i[st]<<endl;    }


    // example 10
    float arr[5]={12.5,10.0,13.5,90.5,0.5};
    float *p1=&arr[0];
    float *p2=p1+3;
    cout<<*p2<<endl;
    cout<<p2-p1;
    return 0;
}