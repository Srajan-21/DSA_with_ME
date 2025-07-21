// Approach 1 using stack o(n)TC SC
// pop from queue push in stack then when quue iis empty pop from stack push in queue =>queue will be reversed

// Aprroach2 Revusrion
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reverse(queue<int> &q){
    stack<int> s;

    while(!q.empty()){
        int elem = q.front();
        q.pop();
        s.push(elem);
    }

    while(!s.empty()){
        int elem = s.top();
        s.pop();
        q.push(elem);
    }
}

void reverseRecursion(queue<int>&q){
    if(q.empty())return ;

    int temp = q.front();
    q.pop();

    reverseRecursion(q);
    q.push(temp);
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    print(q);
    cout<<endl;
    reverse(q);
    print(q);
    cout<<endl;
    reverseRecursion(q);
    print(q);
}