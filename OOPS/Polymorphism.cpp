#include <iostream>
using namespace std;

// Runtime Polymorpism
// Overriding
class Animal{
    public:
    virtual void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Dog:public Animal{
    public:
    // override
    void speak(){
        cout<<"Bark"<<endl;
    }
};

// overriding main
int main(){

    // Dynamic Allocation
    // Animal* a = new Animal();
    // a->speak();

    // Dog* a = new Dog();
    // a->speak();

    // Upcasting
    Animal* a= new Dog();
    a->speak();

    // DownCast
    Dog* b = (Dog* )new Animal();
    b->speak();
    // Static allocation
    // Dog d;
    // d.speak();
}

// // Operator overloading
// class Param{
//     public:
//         int val;
//         void operator+(Param& o2){
//             int val1=this->val;
//             int val2=o2.val;
//             cout<<val2-val1<<endl;  
//         }
// };

// // Operator Overloading
// int main(){
//     Param o1,o2;
//     o1.val=10;
//     o2.val=3;
//     o1+o2;
//     return 0;
// }
// Function Overloading
// class Maths{
//     public:
//         int sum(int a,int b)
//         {
//             cout<<"1st"<<endl;
//             return a+b;
//         }
//         int sum(int a,int b,int c)
//         {
//             cout<<"2nd"<<endl;
//             return a+b+c;
//         }
//         double sum(int a,float b)
//         {
//             cout<<"3rd"<<endl;
//             return a+b+10;
//         }
//         double sum(int a,double b)
//         {
//             cout<<"4th"<<endl;
//             return a+b;
//         }
// };

// int main(){
//     Maths ob;
//     cout<<ob.sum(2,5)<<endl;
//     cout<<ob.sum(2,5,3)<<endl;
//     cout<<ob.sum(2,5.12)<<endl;
//     cout<<ob.sum(2,5.654f)<<endl;
// }