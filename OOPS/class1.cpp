#include <iostream>
using namespace std;

class Animal{
    private:
    int weight;

   public:
    // state
    int age;
    string name;

    // behavior
    void eat()
    {
        cout<<"Eating"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    // getter fn for private member call
    int getWeight(){
        return weight;
    }

    // setter fn for private member call
    int setWeight(int w)
    {
        weight=w;
    }
};

int main(){

    // static object creation
    Animal ob;
    ob.name="Lion";
    ob.age=2;

    cout<<"Name:"<<ob.name<<endl;
    cout<<"Age:"<<ob.age<<endl;

    ob.eat();
    ob.sleep();

    // Access private members using getter and setter function
    ob.setWeight(20);
    cout<<"Weight:"<<ob.getWeight()<<endl;

    // dynamic object creation

    return 0;
}