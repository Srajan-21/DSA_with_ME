class Solution {
public:

    // TC = O(2^(m+n))
    // SC = O(m+n) recursion stack
    int solveRECURSION(int i , int j , int m , int n , vector<vector<int>>& grid){

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)return 0;
        if(i >= m)return 0;
        if(j >= n)return 0;
        if(grid[i][j] == 1)return 0;

        if(i == m - 1 && j == n - 1)return 1;

        int ans = 0;

        ans += solveRECURSION(i + 1 , j , m , n , grid) + solveRECURSION(i , j + 1 , m , n , grid);

        return ans;
    }

    // Time: O(m × n)
    // Space: O(m × n) + recursion stack
    int solveMEMOIZATION(int i , int j , int m , int n , vector<vector<int>>& dp , vector<vector<int>>& grid){

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)return 0;
        if(i >= m || j >= n)return 0;
        if(grid[i][j] == 1)return 0;

        if(i == m - 1 && j == n - 1)return 1;

        if(dp[i][j] != -1)return dp[i][j];

        int ans = solveMEMOIZATION(i + 1 , j , m , n , dp , grid) + solveMEMOIZATION(i , j + 1 , m , n , dp , grid);

        return dp[i][j] = ans;
    }

    // Time: O(m × n)
    // Space: O(m × n)
    int solveTABULATION(int m , int n , vector<vector<int>>& grid){

        vector<vector<long long>> dp(m , vector<long long>(n , 0));
        dp[m-1][n-1] = (grid[m-1][n-1] == 0);

        for(int i = m-1 ; i >= 0 ; i--)
        {
            for(int j = n-1 ; j >= 0 ; j--)
            {

                if(i == m - 1 && j == n - 1)continue;
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }

                long long down = 0 , right = 0;

                if(i + 1 < m){
                    down = dp[i + 1][j];
                }

                if(j + 1 < n){
                    right = dp[i][j + 1];
                }

                dp[i][j] = down + right;
            }
        }

        return (int)dp[0][0];

    }

    // Time: O(m × n)
    // Space: O(n)
    int solveSPACEOPTIMIZATION(int m , int n , vector<vector<int>>& grid){

        vector<long long> next(n , 0);

        for(int i = m - 1 ; i >= 0 ; i--){
            vector<long long> curr(n , 0);

            for(int j = n - 1 ; j >= 0 ; j--){

                if(i == m-1 && j == n-1){
                    curr[j] = grid[i][j] == 0;
                    continue;
                }

                if(grid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }

                long long down = 0 , right = 0;

                if( i + 1 < m)
                    down = next[j];

                if(j + 1 < n)
                    right = curr[j + 1];

                curr[j] = down + right;
            }

            next = curr;
        }

        return next[0];

    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
        return 0;
        
        return solveSPACEOPTIMIZATION(m , n , grid);

        // return solveTABULATION(m , n , grid);

        // vector<vector<long long>> dp(m , vector<long long>(n , -1));
        // return solveMEMOIZATION(0 , 0 , m , n , dp , grid);

        // return solveRECURSION(0 , 0 , m , n , grid);
        
    }
};