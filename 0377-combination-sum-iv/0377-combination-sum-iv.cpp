class Solution {
public:

    // Tabulation
    // TC - O(N × T) SC - O(T)
    int solveTABULATION(vector<int>& nums , int target){

        vector<unsigned int> dp(target + 1 , 0);
        dp[0] = 1;

        for(int i = 1 ; i <= target ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(i >= nums[j]){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }

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

        return solveTABULATION(nums , target);

        // vector<int>dp(target + 1 , -1);
        // return solveMEMOIZATION(nums , target , dp);

        // return solveRECURSION(nums , target);
        
    }
};