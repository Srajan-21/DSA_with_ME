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

    // Time: O(m × n)
    // Space: O(m × n)
    int solveMEMOIZATION(int i , int j , int m , int n , vector<vector<int>>& dp){

        if(i >= m || j >= n)return 0;

        if(i == m - 1 && j == n - 1)return 1;

        if(dp[i][j] != -1)return dp[i][j];

        int ans = solveMEMOIZATION(i + 1 , j , m , n , dp) + solveMEMOIZATION(i , j + 1 , m , n , dp);

        return dp[i][j] = ans;
    }

    // Time: O(m × n)
    // Space: O(m × n)
    int solveTABULATION(int m , int n){

        vector<vector<int>> dp(m , vector<int>(n , 0));
        dp[m-1][n-1] = 1;

        for(int i = m-1 ; i >= 0 ; i--)
        {
            for(int j = n-1 ; j >= 0 ; j--)
            {

                if(i == m - 1 && j == n - 1)continue;

                int down = 0 , right = 0;

                if(i + 1 < m){
                    down = dp[i + 1][j];
                }

                if(j + 1 < n){
                    right = dp[i][j + 1];
                }

                dp[i][j] = down + right;
            }
        }

        return dp[0][0];

    }

    // Time: O(m × n)
    // Space: O(n)

    int uniquePaths(int m, int n) {

        return solveTABULATION(m , n);

        // vector<vector<int>> dp(m , vector<int>(n , -1));
        // return solveMEMOIZATION(0 , 0 , m , n , dp);

        // return solveRECURSION(0 , 0 , m , n);
        
    }
};