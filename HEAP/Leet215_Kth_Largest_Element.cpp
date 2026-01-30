#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// O(n log k) time complexity and O(k) space complexity
int KthLargest(vector<int>& nums , int k)
{
    priority_queue<int , vector<int> , greater<int>> pq;

    for(int i = 0 ; i < k ; i++)
    {
        pq.push(nums[i]);
    }

    for(int i = k ; i <nums.size() ; i++)
    {
        if(nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

// O(n log k) time complexity and O(k) space complexity
int KthSmallest(vector<int>& nums , int k)
{
    priority_queue<int> pq;
    for(int i = 0 ; i < k ; i++)
    {
        pq.push(nums[i]);
    }

    for(int i = k ; i <= nums.size() ; i++)
    {
        if(nums[i] < pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    int k = 2;

    cout<<"The Kth Largest Element is : "<<KthLargest(arr , k)<<endl;
    cout<<endl<<endl;
    cout<<"The Kth Smallest Element is : "<<KthSmallest(arr , k)<<endl;

    return 0;
}