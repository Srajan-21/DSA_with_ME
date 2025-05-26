#include <iostream>
using namespace std;
// Inheritance 
// class Animal{
//     public :
//         int age;
//         int weight;

//         void eat(){
//             cout<<"Eating"<<endl;
//         }
// };

// class Dog:public Animal{

// };

// Single Inheritance
class Animal{
    public :
        int age=5;
};

class Dog:public Animal{
    public :
        void print(){
            cout<<this->age;        
    }

};

// Multilevel Inheritance
class Fruit{
    public :
        int age;
};

class Mango:public Fruit{
    public :
       int weight;
};

class Alphonso:public Mango{
    public :
       int sugar;
};


// Multiple Inheritance
class A{
    public :
        int a=410;
};

class B{
    public :
        int a=110;
};

class C:public B,public A{
    public :
       int c;
};


// Heirarchial Inheritnce
class A1{
    public :
        int age = 5;
};

class B1:public A1{
};

class C1:public A1{
};
 
//for multiple Inheritance diamond problem
int main(){
    C ob;
    cout<<ob.A::a<<","<<ob.B::a;
    return 0;
}