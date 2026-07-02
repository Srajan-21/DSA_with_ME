class Solution {
public:

    int firstOcc(vector<int>& nums , int target){
        int l = 0 , h = nums.size()-1;
        int ans = -1;

        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m] == target){
                ans = m;
                h = m-1;
            }
            else if(nums[m] < target)
                l = m + 1;
            else h = m - 1;
        }
        return ans;
    }

    int lastOcc(vector<int>& nums , int target){
        int l = 0 , h = nums.size()-1;
        int ans = -1;

        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m] == target){
                ans = m;
                l = m + 1;
            }
            else if(nums[m] < target)
                l = m + 1;
            else h = m - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        return {firstOcc(nums,target) , lastOcc(nums,target)};
        
    }
};