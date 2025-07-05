#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void insertAtBottom(stack<int>& s , int target){
        if(s.empty()){
            s.push(target);
            return;
        }

        int topElement = s.top();
        s.pop();

        insertAtBottom(s , target);
        s.push(topElement);

}

void reverseStack(stack<int>& s)
{
    // base case
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s,target);
}

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    
    // insertAtBottom(s);
    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}