class Solution {
public:

    const int INF = 1e9;

    // RECURSION 
    // Time Complexity = O(2^n)
    // Space Complexity = O(n)
    int solveRECURSION(vector<int>& cost , vector<int>& time , int index , int remaining){

        if(remaining <= 0)return 0;
        if(index == cost.size())return INF;

        int skip = 0 + solveRECURSION(cost , time , index + 1 , remaining);

        int take = cost[index] + solveRECURSION(cost , time , index + 1 , remaining - (1 + time[index]));

        return min(skip , take);

    }

    // MEMOIZATION
    // TC - O(n^2)
    // SC - O(n^2)DP + O(n)recursion stack
    int solveMEMOIZATION(vector<int>& cost , vector<int>& time , int index , int remaining ,  vector<vector<int>> &dp){

        if(remaining <= 0)return 0;
        if(index == cost.size())return INF;

        if(dp[index][remaining] != -1)return dp[index][remaining];

        int skip = 0 + solveMEMOIZATION(cost , time , index + 1 , remaining , dp);

        int take = cost[index] + solveMEMOIZATION(cost , time , index + 1 , remaining - (1 + time[index]) , dp);

        dp[index][remaining] = min(skip , take);

        return dp[index][remaining];
    }

    // TABULATION
    // TC - O(n^2)
    // SC - O(n^2)DP 
    int solveTABULATION(vector<int>& cost , vector<int>& time){
        int n = cost.size();
        vector<vector<int>> dp(n + 1 ,vector<int>(n + 1 , 0));

        for(int i = 0 ; i <= n ;i++){
            dp[i][0] = 0;
        }
        for(int rem = 1 ; rem <= n ; rem++){
            dp[n][rem] = INF;
        }

        for(int index = n - 1 ; index >= 0 ; index--){
            for(int remaining = 1 ; remaining <= n ; remaining++){

                int skip = dp[index + 1][remaining];
                int newRem = max(0 , remaining - ( 1 + time[index]));

                int take = cost[index] + dp[index + 1][newRem];

                dp[index][remaining] = min(skip , take);
            }
        }

        return dp[0][n];
    }

    // TABULATION
    // TC - O(n^2)
    // SC - O(n) 
    int solveSPACEOPTIMIZATION(vector<int>& cost , vector<int>& time){

        int n = cost.size();
        vector<int> next(n + 1 , INF);
        vector<int> curr(n + 1 , INF);

        next[0] = 0;

        for(int index = n - 1 ; index >= 0 ; index--){
            curr[0] = 0;

            for(int rem = 1 ; rem  <= n ; rem++){

                int skip = next[rem];
                int remaining = max( 0 , rem - (1 + time[index]));

                int take = cost[index] + next[remaining];
                curr[rem] = min(skip , take);
            }

            next = curr;
        }

        return next[n];
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        return solveSPACEOPTIMIZATION(cost , time); 
        // return solveTABULATION(cost , time);

        // vector<vector<int>> dp(n + 1 ,vector<int>(n + 1 , -1));
        // return solveMEMOIZATION(cost , time , 0 , n , dp);
        
        // return solveRECURSION(cost , time , 0 , n);
        
    }
};