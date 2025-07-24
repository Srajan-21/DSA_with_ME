#include <iostream>
using namespace std;

class Deque{
    public:
    int*arr;
    int size , front , rear;

    Deque(int size){
        this->size = size;
        arr = new int[size]();
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        if((front == 0 && rear == size-1) || (rear + 1) % size == front){
            cout<<"Q is full cant push at rear"<<endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data){
        if((front == 0 && rear == size-1) || (rear + 1) % size == front){
            cout<<"Q is full cant push at front"<<endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = data;
    }

    void popFront(){
        if(front == -1){
            cout<<"Q is Empty , cant pop from front";
            return;
        }
        else if(front == rear){
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popRear(){
        if(front == -1){
            cout<<"Q is Empty , cant pop from rear";
            return;
        }
        else if(front == rear){
            arr[front] = -1;
            front = rear = -1;
        }
        else if(rear == 0){
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }

    void print(){
        if (front == -1) {
        cout << "Deque is empty" << endl;
        return;
        }

        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

};

int main(){
    Deque q(10);
    q.print();

    q.pushRear(1);
    q.print();

    q.pushRear(2);
    q.print();

    q.pushFront(3);
    q.print();

    q.pushRear(4);
    q.print();

    q.pushRear(5);
    q.print();

    q.pushFront(6);
    q.print();

    q.pushRear(7);
    q.print();

    q.pushRear(8);
    q.print();

    q.pushRear(9);
    q.print();

    q.pushFront(10);
    q.print();
    q.pushFront(10);
    q.pushRear(9);

    q.popFront();
    q.print();
    q.popRear();
    q.print();
}