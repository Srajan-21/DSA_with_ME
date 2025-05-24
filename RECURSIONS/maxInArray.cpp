#include <iostream>
#include <limits.h>
using namespace std;

void maximum(int arr[],int n,int i,int& max)
{
    if(i>=n)
        return;
    
    if(max<arr[i])
    {
        max=arr[i];
    }

    maximum(arr,n,i+1,max);
}

int main()
{
    int arr[10]={10,30,15,21,44,26,17}; 
    int n=sizeof(arr)/sizeof(int);
    int i=0;
    int max=INT_MIN;
    maximum(arr,n,i,max);
    cout<<max;
}