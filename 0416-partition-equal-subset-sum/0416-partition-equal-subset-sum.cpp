class Solution {
public:

    // Time Complexity: O(2^n)
    // Space Complexity: O(n)   // recursion stack
    bool solveRECURSION(vector<int>& nums , int i , int target)
    {
        if(target == 0)
            return true;

        if(i == 0)
            return nums[0] == target;

        bool notTake = solveRECURSION(nums , i - 1 , target);
        bool take = false;
        if(nums[i] <= target)
            take = solveRECURSION(nums , i - 1 , target - nums[i]);

        return take || notTake;
    }

    // Time Complexity: O(n * (totSum / 2)) ≈ O(n * totSum)
    // Space Complexity: O(n * (totSum / 2)) + O(n)
    int solveMEMOIZATION(vector<int>& nums , int i , int target , vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;

        if(i == 0)
            return nums[0] == target;

        if(dp[i][target] != -1)
            return dp[i][target];

        bool notTake = solveMEMOIZATION(nums , i - 1 , target , dp);
        bool take = false;
        if(nums[i] <= target)
            take = solveMEMOIZATION(nums , i - 1 , target - nums[i] , dp);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int totSum = 0;
        for(auto & i : nums)
            totSum += i;

        if(totSum % 2)return false;

        vector<vector<int>> dp(n , vector<int>(totSum + 1 , -1));
        return solveMEMOIZATION(nums , n - 1 , totSum / 2 , dp);

        // return solveRECURSION(nums , n - 1 , totSum / 2);

    }
};