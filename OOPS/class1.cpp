#include <iostream>
using namespace std;

class Animal{
    private:
    int weight;

   public:
    // state
    int age;
    string name;

    // CONSTRUCTOR
    // Default constructor
    Animal ()
    {
        this->age=age;
        this->weight=weight;
        this->name=name;
        cout<<"Default constructor Called"<<endl;
    }

    // Parameterised Constructor
    Animal(int age)
    {
        this->age=age;
        cout<<"Parameterised Constructor 1 called"<<endl;
    }

    Animal(int age , int weigth)
    {
        this->age=age;
        this->weight=weight;
        cout<<"Parameterised Constructor 2"<<endl;
    }

    // coopy constructor
    Animal(Animal& obj)
    {
        this->age=obj.age;
        this->weight=obj.weight;
        this->name=obj.name;
        cout<<"Copy Constructor Called"<<endl;
    }

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
    // Animal ob;
    // ob.name="Lion";
    // ob.age=2;

    // cout<<"Name:"<<ob.name<<endl;
    // cout<<"Age:"<<ob.age<<endl;

    // ob.eat();
    // ob.sleep();

    // // Access private members using getter and setter function
    // ob.setWeight(20);
    // cout<<"Weight:"<<ob.getWeight()<<endl;

    // dynamic object creation
    // Animal* suresh = new Animal;

    // // (*suresh).age = 15;
    // // (*suresh).name = "billi";

    // // alternate
    // suresh->age = 17;
    // suresh->name="baby";

    // cout<<suresh->age;
    // cout<<suresh->name;
    // suresh->eat();
    // suresh->sleep();


    // constructor calling
    Animal a;
    a.age=20;
    a.setWeight(60);
    a.name="ABC";
    Animal *b= new Animal(10);
    Animal * c= new Animal(10,100);
    Animal d=a;

    return 0;
} 