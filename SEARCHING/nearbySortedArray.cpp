#include <iostream>
using namespace std;

int binarySearch( int arr[] , int size , int target)
{
    int start=0;
    int end=size-1; 

    while(start<=end)
    {
         int mid=start+(end-start)/2;

        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid-1]==target && mid-1>=start)
        {
            return mid-1;
        }
        if(arr[mid+1]==target && mid+1<=end)
        {
            return mid+1;
        }

         if (target<arr[mid])
        {
            end=mid-2;
        }
        else
        {
            start=mid+2;
        }        
    }
    return -1;
}

int main(){
    int arr[] = {10,3,40,20,50,80,70};
        int size=sizeof(arr)/sizeof(int);

    int target = 80;

    cout<<"iindex"<<binarySearch(arr,size,target);
    return 0;
}   