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
    int solveMEMOIZATION(vector<int>& cost , vector<int>& time , int index , int remaining ,  vector<vector<int>> &dp){

        if(remaining <= 0)return 0;
        if(index == cost.size())return INF;

        if(dp[index][remaining] != -1)return dp[index][remaining];

        int skip = 0 + solveMEMOIZATION(cost , time , index + 1 , remaining , dp);

        int take = cost[index] + solveMEMOIZATION(cost , time , index + 1 , remaining - (1 + time[index]) , dp);

        dp[index][remaining] = min(skip , take);

        return dp[index][remaining];

    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        vector<vector<int>> dp(n + 1 ,vector<int>(n + 1 , -1));
        return solveMEMOIZATION(cost , time , 0 , cost.size() , dp);
        
        // return solveRECURSION(cost , time , 0 , cost.size());
        
    }
};