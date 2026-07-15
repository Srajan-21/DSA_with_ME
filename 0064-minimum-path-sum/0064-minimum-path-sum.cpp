class Solution {
public:

    const int INF = 1e9;

    // Time Complexity : O(2^(m + n))
    // Space Complexity : O(m + n) (recursion stack)
    int solveRECURSION(int i , int j , int m , int n , vector<vector<int>>& grid){

        if(i > m-1 || j > n-1)return INF;

        if(i == m-1 && j == n-1)return grid[i][j];

        int right = solveRECURSION(i + 1 , j , m , n , grid);
        int down = solveRECURSION(i , j + 1 , m , n , grid);

        return grid[i][j] + min(right , down);
    }

    // Time Complexity : O(m × n)
    // Space Complexity : O(m × n) + O(m + n) (recursion stack)
    int solveMEMOIZATION(int i , int j , int m , int n , vector<vector<int>>& grid , vector<vector<int>> &dp){

        if(i > m-1 || j > n-1)return INF;

        if(i == m-1 && j == n-1)return grid[i][j];

        if(dp[i][j] != -1)return dp[i][j];

        int right = solveMEMOIZATION(i + 1 , j , m , n , grid , dp);
        int down = solveMEMOIZATION(i , j + 1 , m , n , grid , dp);

        return dp[i][j] = grid[i][j] + min(right , down);
    }

    // Time Complexity : O(m × n)
    // Space Complexity : O(m × n)
    int solveTABULATION(int m , int n , vector<vector<int>>& grid){

        vector<vector<int>> dp(m , vector<int>(n , 0));

        for(int i = m - 1 ; i >= 0 ; i--)
        {
            for(int j = n - 1 ; j >= 0 ; j--){

                if(i == m - 1 && j == n - 1){
                    dp[i][j] = grid[i][j];
                }

                else{
                    int right = INF;
                    int down = INF;

                    if(i + 1 < m){
                        right = dp[i + 1][j];
                    }

                    if(j + 1 < n){
                        down = dp[i][j + 1];
                    }

                    dp[i][j] = grid[i][j] + min(right , down);
                }
            }
        }
        return dp[0][0];
    }

    // Time Complexity : O(m × n)
    // Space Complexity : O(n)
    int solveSPACEOPTIMIZATION(int m , int n , vector<vector<int>>& grid){

        vector<int> next(n , 0);

        for(int i = m - 1 ; i >= 0 ; i--)
        {
            vector<int> curr(n , 0);
            for(int j = n - 1 ; j >= 0 ; j--){

                if(i == m - 1 && j == n - 1){
                    curr[j] = grid[i][j];
                }

                else{
                    int right = INF;
                    int down = INF;

                    if(i + 1 < m){
                        right = next[j];
                    }

                    if(j + 1 < n){
                        down = curr[j + 1];
                    }

                    curr[j] = grid[i][j] + min(right , down);
                }
            }
            next = curr;
        }
        return next[0];
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        return solveSPACEOPTIMIZATION(m , n , grid);

        // return solveTABULATION(m , n , grid);

        // vector<vector<int>> dp(m , vector<int>(n , -1));
        // return solveMEMOIZATION(0 , 0 , m , n , grid , dp);

        // return solveRECURSION(0 , 0 , m , n , grid);

    }
};