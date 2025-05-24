#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// METHOD 1
    int binarySearch(vector <int> &nums , int start , int target)
    {
        int end = nums.size()-1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;

        for(int i=0;i<nums.size();i++)
        {
            if(binarySearch(nums,i+1,nums[i]+k)!=-1)
            {
               ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
    }

int main()
{
    vector <int> arr{3,1,4,1,5};
    int k=2;
    cout<<findPairs(arr,k)<<endl;
    return 0;
}