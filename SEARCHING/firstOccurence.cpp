#include <iostream>
using namespace std;


int main(){
    int arr[] = {1,2,3,4,5,6,6,6,7,8};
    int size = sizeof(arr)/sizeof(int);
    int target = 6;

    int start=0;
    int end=size-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(target==arr[mid])
        {
            ans=mid;
            end=mid-1;
        }
        else if(target<arr[mid])
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    
    if(ans==-1)
    cout<<"not found";
    else
    cout<<"first occurence "<<ans;
    return 0;
}