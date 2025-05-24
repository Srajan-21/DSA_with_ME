#include <iostream>
using namespace std;

int binSearch(int arr[],int start,int end,int target)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int expSearch(int arr[],int size,int target)
{
    if(arr[0]==target)
        return 0;
    
    int i=1;
    while(i<size && arr[i]<=target)
    {
        i=i*2;
    }

    return binSearch(arr,i/2,min(i,size-1),target);    
}

int main()
{
    int arr[]={3,4,5,6,11,13,14,15,56,70};
    int size=sizeof(arr)/sizeof(int);
    int target=13;
    int ans=expSearch(arr,size,target);
    cout<<ans;
    return 0;
}