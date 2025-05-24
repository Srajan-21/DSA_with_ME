#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr)
{
    int start=0;
    int end=arr.size()-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(start==end)
        {
            // single element in array
            // sorted array no rotation
            return start;
        }

        // mid agar pivot pe aa gya
        if(mid<=end && arr[mid]>arr[mid+1])
             return mid;

        // mid agar pivot k ekk aage aya
        if(mid-1>=start && arr[mid-1]>arr[mid])
             return mid-1;

        if(arr[start]>arr[mid])
             end=mid-1;
        else
            start=mid+1;        
            }
    return -1;
}
int main()
{
    vector<int> arr{3,1};
    int ans=findPivot(arr);
    if(ans==-1)
    cout<<"not found";
    else{
        cout<<"Index="<<ans<<endl;
        cout<<"Value="<<arr[ans]<<endl;
    }
    return 0;
}