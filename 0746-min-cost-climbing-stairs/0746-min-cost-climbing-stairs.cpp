class Solution {
public:

    int solve2(vector<int>&cost , int n , vector<int>& dp){
        // Base Case
        if(n==0 || n==1)return cost[n];

        if(dp[n] != -1)return dp[n];

        dp[n] = cost[n] + min(solve2(cost , n-1 , dp) , solve2(cost , n-2 , dp));
        return dp[n];
    }

    // TLE
    // int solve(vector<int> & cost , int n){
    //     // Base Case
    //     if(n == 0 || n == 1)return cost[n];
    //     int ans = cost[n] + min(solve(cost , n-1) , solve(cost , n-2));
    //     return ans;
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        // Approach 1 Recursion TLE
        // int ans = min(solve(cost , n-1) , solve(cost , n-2));

        // Approach 2
        vector<int>dp (n+1 , -1);
        int ans = min(solve2(cost , n-1 , dp) , solve2(cost , n-2 , dp));
       
        return ans;
    }
};