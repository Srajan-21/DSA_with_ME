#include <iostream>
#include <queue>
using namespace std;

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}


void interleave(queue<int> &q){
    int n = q.size();
    if(q.empty())return;

    int k=(n+1)/2;    
    queue<int> q2;

   for(int i = 0 ; i< k ; i++){
    q2.push(q.front());
    q.pop();
   }

    print(q2);
    cout<<endl;
    print(q);
    cout<<endl;

    int m = q.size();
    while(m--){
        int first = q2.front();
        q.push(first);
        q2.pop();
        int second = q.front();
        q.push(second);
        q.pop();        
    }
    if(!q2.empty())
        q.push(q2.front());
}


int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    print(q);
    cout<<endl;
    interleave(q);
    print(q);
    return 0;
}