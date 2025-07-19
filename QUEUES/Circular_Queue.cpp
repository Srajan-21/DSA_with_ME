#include <iostream>
using namespace std;

class CirQueue{
    public :
    int *arr;
    int size , front , rear;

    CirQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        if (front == (rear+1)%size){
            cout<<"Queue  is full cant insert"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        if(front == -1){
            cout<<"Q is empty cant pop";
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else {
            front++;
        }
    }

    int getFront(){
        return arr[front];
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main(){
    CirQueue q(5);
    q.push(5);
    q.push(2);
    q.push(1);
    q.push(6);
    q.push(7);
    cout<<q.getFront()<<endl;
    q.pop();
    cout<<q.getFront()<<endl;
    q.push(9);
    cout<<q.getFront()<<endl;
    q.push(9);

}