#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19};

    int start=0,end=sizeof(arr)/sizeof(int);

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==mid+1)
        {
            start=mid+1;
        }    
        
        else{
            end = mid-1;
        }
    } 
    cout<<"root="<<start+1<<endl;
    return 0;
}