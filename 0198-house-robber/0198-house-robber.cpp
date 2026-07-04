class Solution {
public:

    // TLE
    int solveRecursion(vector<int>& nums , int n){

        if(n < 0)return 0;

        int including = solveRecursion(nums,n-2) + nums[n];
        int excluding = solveRecursion(nums,n-1);

        return max(including , excluding);
        
    }

    // TC - O(n) SC-O(n)
    int solveMemoization(vector<int>& nums , int n  , vector<int>&dp){

        if(n < 0)return 0;
        if(dp[n] != -1)return dp[n];

        int including = solveMemoization(nums , n-2 , dp) + nums[n];
        int excluding = solveMemoization(nums , n-1 , dp);

        dp[n] = max(including, excluding);
        return dp[n];
    }

    // TC - O(n) SC - O(n)
    int solveTabular(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = max(0,nums[0]);

        for(int i = 1 ; i < n ; i++){
            int inc = (i>=2 ? dp[i-2] : 0) + nums[i];
            int exc = dp[i-1];
            dp[i] = max(inc,exc);
        }
        return dp[n-1];
    }

    // TC - O(n) SC - O(1)
    int solveSpaceOptimization(vector<int>& nums){
        int n = nums.size();

        int prev2 = 0;
        int prev1 = max(0,nums[0]);

        for(int i = 1; i < n ; i++){
            int inc = prev2 + nums[i];
            int exc = prev1;

            int ans = max(inc , exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        long long ans = 0;
        ans += solveSpaceOptimization(nums);
        return ans;

        // long long ans = 0;
        // ans += solveTabular(nums);
        // return ans;

        // long long ans = 0;
        // ans += solveRecursion(nums , n-1);
        // return ans;

        // return solveMemoization(nums,n-1,dp);
    }
};