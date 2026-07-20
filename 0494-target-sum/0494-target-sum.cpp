class Solution {
public:

    int solve(vector<int>& nums, int target , int i)
    {
        int n = nums.size();
        if(i == n)return target == 0;

        int pos = solve(nums , target - nums[i] , i + 1);
        int neg = solve(nums , target + nums[i] , i + 1);

        return pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums , target , 0);
    }
};