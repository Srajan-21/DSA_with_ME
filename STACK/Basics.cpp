#include <iostream>
#include <stack>
using namespace std;

int main(){

    // Creation
    stack <int> st;

    // Insertion 10 20 30 40
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Pop
    st.pop(); //10 20 30

    // top 
    cout<<"Element at Top : "<<st.top()<<endl; //30

    // size
    cout<<"Size of stack : "<<st.size()<<endl; //3

    // empty or not
    if(st.empty())
        cout<<"Stack is Empty "<<endl;
    else
        cout<<"Stack is not Empty"<<endl;

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    cout<<endl;

    if(st.empty())
        cout<<"Stack is Empty "<<endl;
    else
        cout<<"Stack is not Empty"<<endl;

}