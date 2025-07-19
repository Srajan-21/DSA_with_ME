#include <iostream>
#include <queue>
using namespace std;

int main(){

    // Creation
    queue<int> q;
    // Insertion 5 4 2 8
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(8);

    cout<<"Size of queue : "<<q.size()<<endl; //4
    cout<<"Element at front : "<<q.front()<<endl; //5

    // Pop
    q.pop(); //4 2 8

    cout<<"Size of queue : "<<q.size()<<endl; //3

    // top 
    cout<<"Element at front : "<<q.front()<<endl; //4

    // size
    // cout<<"Size of stack : "<<st.size()<<endl; //3

    // empty or not
    if(q.empty())
        cout<<"Queue is Empty "<<endl;
    else
        cout<<"Queue is not Empty"<<endl;

    // printing 4 2 8
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;

    if(q.empty())
        cout<<"Queue is Empty "<<endl;
    else
        cout<<"Queue is not Empty"<<endl;

}