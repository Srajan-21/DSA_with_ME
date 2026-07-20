class Solution {
public:

    // TC - O(n×2001) ≈ O(n) (or O(n×sum))
    // SC - O(n×2001)+O(n) ≈ O(n×sum)
    int solveMEMOIZATION(vector<int>& nums, int target , int i , vector<vector<int>>& dp)
    {
        int n = nums.size();
        if(target < -1000 || target > 1000)
            return 0;

        if(i == n)return target == 0;
        int OFFSET = 1000;

        if(dp[i][target + OFFSET] != -1)return dp[i][target + OFFSET];

        int pos = solveMEMOIZATION(nums , target - nums[i] , i + 1 , dp);
        int neg = solveMEMOIZATION(nums , target + nums[i] , i + 1 , dp);

        return dp[i][target + OFFSET] = pos + neg;
    }

    // TC - O(2^n)
    // SC - O(n)
    int solveRECURSION(vector<int>& nums, int target , int i)
    {
        int n = nums.size();
        if(i == n)return target == 0;

        int pos = solveRECURSION(nums , target - nums[i] , i + 1);
        int neg = solveRECURSION(nums , target + nums[i] , i + 1);

        return pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp (n + 1 , vector<int>(2001 , -1));
        return solveMEMOIZATION(nums , target , 0 , dp);
        
        // return solveRECURSION(nums , target , 0);
    }
};