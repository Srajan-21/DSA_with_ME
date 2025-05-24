#include <iostream>
using namespace std;

void print(int n)
{
    // base case
    if(n==0)
        return ;

    // processing
    cout<<n<<" ";

    // recursive relation
    print(n-1);

}

int main(){
    int n=10;

    print(n);
    return 0;
}