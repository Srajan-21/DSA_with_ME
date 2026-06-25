class Solution {
public:

    // Tabulation - Bottom Up
    int solve3(vector<int>&cost , int n){
        vector<int> dp(n+1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2 ; i < n ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }

        return min(dp[n-1] , dp[n-2]);
    }

    // Recursion + Memoization 
    int solve2(vector<int>&cost , int n , vector<int>& dp){
        // Base Case
        if(n==0 || n==1)return cost[n];

        if(dp[n] != -1)return dp[n];

        dp[n] = cost[n] + min(solve2(cost , n-1 , dp) , solve2(cost , n-2 , dp));
        return dp[n];
    }

    // TLE
    int solve(vector<int> & cost , int n){
        // Base Case
        if(n == 0 || n == 1)return cost[n];
        int ans = cost[n] + min(solve(cost , n-1) , solve(cost , n-2));
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        // Approach 1 Recursion TLE
        // int ans = min(solve(cost , n-1) , solve(cost , n-2));

        // Approach 2 Recursion + Memoization 
        // vector<int>dp (n+1 , -1);
        // int ans = min(solve2(cost , n-1 , dp) , solve2(cost , n-2 , dp));

        // Approach 3 Tabulation - Bottom Up
        int ans = solve3(cost , n);

        return ans;
    }
};