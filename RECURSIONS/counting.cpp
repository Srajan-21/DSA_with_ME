#include <iostream>
using namespace std;

void print(int n)
{
    // base case
    if(n==0)
        return ;

    // recursive relation
    print(n-1);

    // processing
    cout<<n<<" ";
}

int main(){
    int n=20;

    print(n);
    return 0;
}