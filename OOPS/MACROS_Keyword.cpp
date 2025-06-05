#include <iostream>
using namespace std;
#define PI 3.1415 

float circle(float r)
{
    return PI*r*r;
}

float perimeter(float r){
    return 2*PI*r;
}

int main(){
    cout<<circle(2.4)<<endl;
    cout<<perimeter(2.4)<<endl;
}
