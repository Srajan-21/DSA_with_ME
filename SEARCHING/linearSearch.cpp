#include <iostream>
using namespace std;

int main(){
    int arr[]={1,5,9,7,6,3,4,8,2};
    int size = sizeof(arr)/sizeof(int);
    int target=6;
    int flag=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==target)        
        {
            flag=i;
        }        
    }

    if(flag!=0)
    {
        cout<<"found at "<<flag+1;
    }
    else{
        cout<<"not found";
    }
}