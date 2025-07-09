// top1=-1
// top2=size
// top2-top1==1 no space

#include <iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int top1;
        int top2;

        Stack(int size){
            arr = new int[size]();
            this->size = size;
            top1 = -1; 
            top2 = size;
        }

        void push1(int data){
            if(top2 - top1 == 1){
                cout<<"OVERFLOW in 1"<<endl;
            }
            else{
                top1++;
                arr[top1]=data;
            }
        }

        void pop1(){
            if(top1 == -1){
                cout<<"Underflow in stack 1"<<endl;
            }
            else{
                top1--;
            }
        }

        void push2(int data){
            if(top2 - top1 == 1){
                cout<<"OVERFLOW in 2"<<endl;
            }
            else{
                top2--;
                arr[top2]=data;
            }
        }

        void pop2(){
            if(top2 == size){
                cout<<"Underflow in stack 2"<<endl;
            }
            else{
                top2++;
            }
        }

        void print(){
            cout<<endl;
            cout<<"Top 1 : " << arr[top1] << endl;
            cout<<"Top 2 : " << arr[top2] << endl;

            for(int i = 0 ; i<size ; i++){
                cout << arr[i] << " ";
            }
            cout<<endl;
        }
};

int main(){
    Stack s(12);

    s.push1(1);s.print();
    s.push2(2);s.print();
    s.push1(3);s.print();
    s.push2(4);s.print();
    s.push1(5);s.print();
    s.push2(6);s.print();
    s.push1(7);s.print();
    s.push2(8);s.print();
    s.push1(9);s.print();
    s.push2(10);s.print();
    s.push1(10);s.print();
    s.push2(20);s.print();
    s.push1(10);s.print();
    // s.push1(20);s.print();
}