#include<iostream>
#include <deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    // first window of k size
    for(int i = 0; i < k ; i++){
        // remove smaller element
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }

        // inserting index so that we can checkout of window element
        dq.push_back(i);
    }
    // store answer for 1st window
    ans.push_back(nums[dq.front()]);

    // remaining window process
    for(int i=k ; i <nums.size() ; i++){
    // pout of window element remove
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }

        // inserting index so that we can checkout of window element
        dq.push_back(i);

        // CURRENT WINDOW ANS STORE
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums , k);
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}