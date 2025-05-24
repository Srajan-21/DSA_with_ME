#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int arr[]={5,2,33,6,44,59,65,84,92,105};
    int length=sizeof(arr)/sizeof(int);

    int max=INT_MIN;

    if(length==0)
    {
        cout<<INT_MIN;
    }

    for(int i=0;i<length;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    cout<<max;
    return 0;
}