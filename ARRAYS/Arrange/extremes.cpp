#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={5,6,2,3,4,6};
    int length = sizeof(arr)/sizeof(int);

    int m=0;
    int n=length-1;

    while(true){
        if(m>n)
        break;

        if(m==n)
        {
            cout<<arr[m];
        }
        
        else{
            cout<<arr[m]<<" "<<arr[n]<<" ";
        }
        
        m++;
        n--;
    }
    return 0;
}