#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(int);

    int m=0;
    int n=size-1;
    int t;

    while(m<n)
    {
        swap(arr[m],arr[n]);
        // t=arr[m];
        // arr[m]=arr[n];
        // arr[n]=t;
        m++;
        n--;
    }
    
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}