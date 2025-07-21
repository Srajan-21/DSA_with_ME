#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reverse(queue<int>&q , int k){
    stack<int> s;
    int count = 0;

    if(k <= 0 || k > q.size())return;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k)break;
    }

    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    count = 0;
    while(!q.empty() && q.size()-k != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == q.size()-k)break;
    }
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
    
    reverse(q,5);
    print(q);
}