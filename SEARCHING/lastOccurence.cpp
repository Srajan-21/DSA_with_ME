#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr{1,2,3,4,4,4,4,4,4,5};
    int target=4;
    int start=0,end=arr.size()-1,ans=-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    if(ans==-1)
    cout<<"not found";
    else
    cout<<"index="<<ans;
    return 0;
}