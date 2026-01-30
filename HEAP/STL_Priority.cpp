#include <iostream>
#include <queue>
using namespace std;


int main(){
    
    // Max Heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5); 
    pq.push(1);

    cout<<"Max Heap Top Element: "<<pq.top()<<endl; // 5
    pq.pop();
    cout<<"Max Heap Top Element after pop: "<<pq.top()<<endl; // 4
    cout<<"Max Heap Size: "<<pq.size()<<endl; // 3
    if(pq.empty()){
        cout<<"Max Heap is empty"<<endl;
    } else {
        cout<<"Max Heap is not empty"<<endl;
    }

    cout <<endl<<endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);    
    minHeap.push(2);
    minHeap.push(5);

    cout<<"Min Heap Top Element: "<<minHeap.top()<<endl; // 2
    minHeap.pop();  
    cout<<"Min Heap Top Element after pop: "<<minHeap.top()<<endl; // 4
    cout<<"Min Heap Size: "<<minHeap.size()<<endl; // 2
    if(minHeap.empty()){
        cout<<"Min Heap is empty"<<endl;
    } else {
        cout<<"Min Heap is not empty"<<endl;
    }
    
}


