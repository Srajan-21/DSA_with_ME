#include <iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size , front , rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front == rear){
            cout<<"Queue is Empty";
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront(){
        if(front == rear){
            cout<<"Queue is Empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        return rear-front;
    }
};


int main(){
    Queue q(10);

    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    cout<<"Size : "<<q.getSize()<<endl;
    cout<<"Front : "<<q.getFront()<<endl;

    q.pop();
    cout<<"Size : "<<q.getSize()<<endl;
    cout<<"Front : "<<q.getFront()<<endl;

    if(q.isEmpty()){
        cout<<"Q Empty"<<endl;
    }
    else{
        cout<<"Q Not Empty"<<endl;
    }
}