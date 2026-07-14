class Solution {
public:

    const int MOD = 1e9 + 7;

    // TC = O(3^n)
    int solveRECURSION(int index , int gcd1 , int gcd2 , vector<int>& nums){
        if(index == nums.size()){
            if(gcd1 == gcd2 && gcd1 != 0)
                return 1;
            return 0;
        }

        long long ans = 0;

        ans += solveRECURSION(index + 1 , gcd1 , gcd2 , nums);
        ans += solveRECURSION(index + 1 , gcd(gcd1 , nums[index]) , gcd2 , nums);
        ans += solveRECURSION(index + 1 , gcd1 , gcd(gcd2 , nums[index]) , nums);

        return ans % MOD;
    }

    // MEMOIZATION
    // Time: O(n × 201 × 201)
    // Space: O(n × 201 × 201) (DP table) + O(n) (recursion stack)
    int solveMEMOIZATION(int index , int gcd1 , int gcd2 , vector<int>& nums , vector<vector<vector<int>>> &dp){

        if(index == nums.size()){
            return (gcd1 == gcd2 && gcd1 != 0);
        }

        if(dp[index][gcd1][gcd2] != -1)
            return dp[index][gcd1][gcd2];

        long long ans = 0;

        ans += solveMEMOIZATION(index + 1 , gcd1 , gcd2 , nums , dp);
        ans += solveMEMOIZATION(index + 1 , gcd(gcd1 , nums[index]) , gcd2 , nums , dp);
        ans += solveMEMOIZATION(index + 1 , gcd1 , gcd(gcd2 , nums[index]) , nums , dp);

        return dp[index][gcd1][gcd2] = ans % MOD;
    }


    int subsequencePairCount(vector<int>& nums) {

        int n = nums.size();

        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(201 , vector<int>(201 , -1)));
        return solveMEMOIZATION(0 , 0 , 0 , nums , dp);

        // return solveRECURSION(0 , 0 , 0 , nums);

    }
};