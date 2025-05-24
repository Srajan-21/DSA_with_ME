#include <iostream>
using namespace std;

int climbStairs(int n)
{

    // base case
    if(n==0 || n==1)
    {
        return 1;
    }

    return climbStairs(n-1)+climbStairs(n-2);
}
int main()
{
    int n=5;
    int ans=climbStairs(n);
    cout<<ans;
}