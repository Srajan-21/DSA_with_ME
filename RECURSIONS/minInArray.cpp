#include <iostream>
#include <limits.h>
using namespace std;

void minimum(int arr[],int n,int i,int& mini)
{
    if(i>=n)
        return;
    
    mini=min(mini,arr[i]);

    minimum(arr,n,i+1,mini);
}

int main()
{
    int arr[]={10,30,15,21,44,26,17}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    int mini=INT_MAX;
    minimum(arr,n,i,mini);
    cout<<mini;
}