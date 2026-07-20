class Solution {
public:

    // TC - O(n×2001) ≈ O(n) (or O(n×sum))
    // SC - O(2001) ≈ O(sum)
    int solveSPACE(vector<int>& nums, int target)
    {
        int n = nums.size();
        int OFFSET = 1000;
        vector<int> next(2001 , 0);
        next[OFFSET] = 1;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            vector<int> curr(2001 , 0);
            for(int j = -1000 ; j <= 1000 ; j++)
            {
                int ways = 0;

                if(j - nums[i] >= -1000 && j - nums[i] <= 1000)
                    ways += next[j - nums[i] + OFFSET];

                if(j + nums[i] >= -1000 && j + nums[i] <= 1000)
                    ways += next[j + nums[i] + OFFSET];
            
                curr[j + OFFSET] = ways;
            }
            next = curr;
        }

        if(target < -1000 || target > 1000)
        return 0;
        
        return next[target + OFFSET];
    }

    // TC - O(n×2001) ≈ O(n) (or O(n×sum))
    // SC - O(n×2001) ≈ O(n×sum)
    int solveTABULATION(vector<int>& nums, int target)
    {
        int n = nums.size();
        int OFFSET = 1000;
        vector<vector<int>>dp (n + 1 , vector<int>(2001 , 0));

        dp[n][OFFSET] = 1;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            for(int j = -1000 ; j <= 1000 ; j++)
            {
                int ways = 0;

                if(j - nums[i] >= -1000 && j - nums[i] <= 1000)
                    ways += dp[i + 1][j - nums[i] + OFFSET];

                if(j + nums[i] >= -1000 && j + nums[i] <= 1000)
                    ways += dp[i + 1][j + nums[i] + OFFSET];
            
                dp[i][j + OFFSET] = ways;
            }
        }

        if(target < -1000 || target > 1000)
        return 0;
        
        return dp[0][target + OFFSET];
    }
    
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
        return solveSPACE(nums , target);
        // return solveMEMOIZATION(nums , target , 0 , dp);
        // return solveTABULATION(nums , target);
        // return solveRECURSION(nums , target , 0);
    }
};