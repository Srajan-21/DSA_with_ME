#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str="Srajan";
    cout<<str<<endl;

    cout<<"length:"<<str.length()<<endl;
    cout<<"isEmpty:"<<str.empty()<<endl;
    str.push_back('A');
    cout<<str<<endl;
    str.pop_back();
    cout<<str<<endl;
    cout<<str.substr(2,3)<<endl;
    cout<<str<<endl;
    return 0;
}