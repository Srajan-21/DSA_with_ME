// CONSTRAINTS
// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector <int> arr)
{
    int start=0;
    int end=arr.size()-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        // single element
        if(start==end)
            return start;

        if(arr[mid]>arr[mid+1] && mid<=end)
            return mid;
        
        if(arr[mid]<arr[mid-1] && mid-1>=start)
            return mid-1;

        if(arr[mid]<arr[start])
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}

int binarySearch(vector <int> arr,int start,int end,int target)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]>target)
        end=mid-1;
        else
        start=mid+1;
    }
    return -1;
}

int search(vector <int> arr , int target)
{
    int pivotIndex=findPivot(arr);
    int ans=0;
    if(target>arr[0] && target<arr[pivotIndex])
        ans=binarySearch(arr,0,pivotIndex,target);
    else
        ans=binarySearch(arr,pivotIndex+1,arr.size()-1,target);

    return ans;
}

int main()
{
    vector <int >arr{1};
    int target=0;
    cout<<search(arr,target);
    return 0;
}
  