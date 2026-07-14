class Solution {
public:

    // Tabulation
    // TC - O(N × T) SC - O(T)
    

    // MEMOIZATION
    // TC - O(N × T)
    // SC - O(T) (DP array) + O(T) (recursion stack) = O(T)
    int solveMEMOIZATION(vector<int>& nums, int target , vector<int>& dp){

        if(target < 0)return 0;
        if(target == 0)return 1;

        if(dp[target] != -1)
            return dp[target]; 

        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            ans += solveMEMOIZATION(nums , target - nums[i] , dp);
        }

        dp[target] = ans;

        return dp[target];
    }

    // TLE
    // Recursion
    // TC - O(N^Target) (exponential)
    // SC - O(Target) (recursion stack)
    int solveRECURSION(vector<int>& nums, int target){

        if(target < 0)return 0;
        if(target == 0)return 1;

        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            ans += solveRECURSION(nums , target - nums[i]);
        }

        return ans;

    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<int>dp(target + 1 , -1);
        return solveMEMOIZATION(nums , target , dp);

        // return solveRECURSION(nums , target);
        
    }
};