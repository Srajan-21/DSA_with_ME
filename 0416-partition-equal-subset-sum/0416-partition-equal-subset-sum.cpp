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

    // Time Complexity: O(n * (totSum / 2)) ≈ O(n * totSum)
    // Space Complexity: O(n * (totSum / 2)) ≈ O(n * totSum)
    int solveTABULATION(vector<int>& nums , int target)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n , vector<bool>(target + 1 , 0));

        for(int i = 0 ; i < n ; i++)
        {
            dp[i][0] = true;
        }

        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j <= target ; j++)
            {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if(nums[i] <= j)
                {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int totSum = 0;
        for(auto & i : nums)
            totSum += i;

        if(totSum % 2)return false;

        return solveTABULATION(nums , totSum / 2);

        // vector<vector<int>> dp(n , vector<int>(totSum + 1 , -1));
        // return solveMEMOIZATION(nums , n - 1 , totSum / 2 , dp);

        // return solveRECURSION(nums , n - 1 , totSum / 2);

    }
};