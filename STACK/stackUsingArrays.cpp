#include <iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

        Stack(int size){
            arr = new int[size];
            this->size = size;
            top = -1;
        }

        // push-> space available (size - top > 1)-> insert top++ arr[top]=data
        //     ->space unavailable -> overflow
        void push(int data)
        {
            if(size - top > 1){
                top++;
                arr[top] = data;
            }
            else{
                cout<<"Stack Oerflow"<<endl;
            }
        }

        // push-> space available top--
        //     ->stack empty-> underflow
        void pop(){
            if(top == -1){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                // stack not empty
                top--;
            }
        }

        int peek(){
            if(top == -1){
                cout<<"No Element in stack"<<endl;
            }
            else{
                return arr[top];
            }
        }

        int getSize(){
            return top+1;
        }

        bool isEmpty(){
            return (top == -1)?true : false;
        }
};

int main(){
    Stack s(10);

    cout<<s.isEmpty()<<endl;
    s.push(10);
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    s.push(20);
    cout<<s.getSize()<<endl;
}