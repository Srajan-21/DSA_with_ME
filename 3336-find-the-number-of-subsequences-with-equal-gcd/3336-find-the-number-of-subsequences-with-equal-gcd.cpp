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

    // TABULATION TLE
    // 3D DP: O(n × 201 × 201)
    int solveTABULATION(vector<int>& nums){

        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(201 , vector<int>(201 , 0)));

        // BASE CASE
        for(int g = 1 ; g <= 200 ; g++){
            dp[n][g][g] = 1;
        }

        for(int index = n - 1 ; index >= 0 ; index--)
        {
            for(int gcd1 = 0 ; gcd1 <= 200 ; gcd1++)
            {
                for(int gcd2 = 0 ; gcd2 <= 200 ; gcd2++){

                    long long ans = 0;

                    ans += dp[index + 1][gcd1][gcd2];
                    ans += dp[index + 1][gcd(gcd1 , nums[index])][gcd2];
                    ans += dp[index + 1][gcd1][gcd(gcd2 , nums[index])];

                    dp[index][gcd1][gcd2] = ans % MOD;
                }
            }
        }

        return dp[0][0][0];

    }


    // SPACE OPTIMIZATION 
    // 2D DP: O(201 × 201)
    int solveSPACEOPTIMIZATION(vector<int>& nums) {

        const int MAX = 200;
        int n = nums.size();

        // Precompute gcd
        vector<vector<int>> G(MAX + 1, vector<int>(MAX + 1));

        for (int i = 0; i <= MAX; i++) {
            for (int j = 0; j <= MAX; j++) {
                G[i][j] = gcd(i, j);
            }
        }

        vector<vector<int>> next(MAX + 1, vector<int>(MAX + 1, 0));

        // Base case
        for (int g = 1; g <= MAX; g++) {
            next[g][g] = 1;
        }

        for (int idx = n - 1; idx >= 0; idx--) {

            vector<vector<int>> curr(MAX + 1, vector<int>(MAX + 1, 0));

            int x = nums[idx];

            for (int g1 = 0; g1 <= MAX; g1++) {

                int ng1 = G[g1][x];

                for (int g2 = 0; g2 <= MAX; g2++) {

                    int ng2 = G[g2][x];

                    long long ans = next[g1][g2];

                    ans += next[ng1][g2];

                    ans += next[g1][ng2];

                    curr[g1][g2] = ans % MOD;
                }
            }

            swap(next, curr);
        }

        return next[0][0];
    }


    int subsequencePairCount(vector<int>& nums) {

        int n = nums.size();

        return solveSPACEOPTIMIZATION(nums);

        // return solveTABULATION(nums);

        // vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(201 , vector<int>(201 , -1)));
        // return solveMEMOIZATION(0 , 0 , 0 , nums , dp);

        // return solveRECURSION(0 , 0 , 0 , nums);

    }
};