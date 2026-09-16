class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(k + 1, vector<long long>(2, 0));
        dp[0][0] = 1;  
        dp[0][1] = 1;  

        for (int i = 0; i < n - 1; i++) {  
            vector<vector<long long>> ndp(k + 1, vector<long long>(2, 0));
            for (int j = 0; j <= k; j++) {
                if (dp[j][0]) {
                    ndp[j][0] = (ndp[j][0] + dp[j][0]) % MOD;  
                    ndp[j][1] = (ndp[j][1] + dp[j][0]) % MOD;  
                }
                if (dp[j][1]) {
                    ndp[j][1] = (ndp[j][1] + dp[j][1]) % MOD;  
                    if (j < k) {
                        ndp[j+1][0] = (ndp[j+1][0] + dp[j][1]) % MOD; 
                        ndp[j+1][1] = (ndp[j+1][1] + dp[j][1]) % MOD; 
                    }
                }
            }
            dp = ndp;
        }

        return (int)dp[k][0];
    }
};