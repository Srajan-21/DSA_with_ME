#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr{1,2,3,4,5,6,8,6,3};
    int start=0,end=arr.size()-1;

    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<arr[mid+1])
        {
            start=mid+1;
        }
        else{
            end=mid;
        }
    }

    
    cout<<"index="<<start;
    return 0;
}