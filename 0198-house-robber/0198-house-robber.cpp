class Solution {
public:

    // TC - O(n) SC-O(n)
    int solveMemoization(vector<int>& nums , int n  , vector<int>&dp){

        if(n < 0)return 0;
        if(dp[n] != -1)return dp[n];

        int including = solveMemoization(nums , n-2 , dp) + nums[n];
        int excluding = solveMemoization(nums , n-1 , dp);

        dp[n] = max(including, excluding);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solveMemoization(nums,n-1,dp);
    }
};