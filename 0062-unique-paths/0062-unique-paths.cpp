class Solution {
public:


    // TC = O(2^(m+n))
    // SC = O(m+n) recursion stack
    int solveRECURSION(int i , int j , int m , int n){

        if(i >= m)return 0;
        if(j >= n)return 0;

        if(i == m - 1 && j == n - 1)return 1;

        int ans = 0;

        ans += solveRECURSION(i + 1 , j , m , n);
        ans += solveRECURSION(i , j + 1 , m , n);

        return ans;
    }

    int solveMEMOIZATION(int i , int j , int m , int n , vector<vector<int>>& dp){

        if(i >= m || j >= n)return 0;

        if(i == m - 1 && j == n - 1)return 1;

        if(dp[i][j] != -1)return dp[i][j];

        int ans = solveMEMOIZATION(i + 1 , j , m , n , dp) + solveMEMOIZATION(i , j + 1 , m , n , dp);

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solveMEMOIZATION(0 , 0 , m , n , dp);

        // return solveRECURSION(0 , 0 , m , n);
        
    }
};