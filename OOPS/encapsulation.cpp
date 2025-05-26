#include <iostream>
using namespace std;
// Encapsulation
// class Animal{
//     public :
//         int age;
//         int weight;

//         void eat(){
//             cout<<"Eating"<<endl;
//         }
// };

// Perfect Encapsulation
class Animal{
    // Data members private
    private:
        int age;
        int weight;

    public:
        void eat(){
            cout<<"Eating"<<endl;
        }

        int getAge(){
            return this->age;
        }
        void setAge(int age){
            this->age = age;
        }

        int getWeight(){
            return this->weight;
        }
        void setWeight(int weight){
            this->weight = weight;
        }
};

int main(){
    cout<<"Hello World"<<endl;
    Animal* ob = new Animal();
    ob->setAge(65);
    cout<<ob->getAge()<<endl;
    ob->setWeight(75);
    cout<<ob->getWeight()<<endl;

    ob->eat();
    return 0;
}