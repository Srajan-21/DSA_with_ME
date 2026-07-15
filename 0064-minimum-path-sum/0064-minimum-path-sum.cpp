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

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solveMEMOIZATION(0 , 0 , m , n , grid , dp);

        // return solveRECURSION(0 , 0 , m , n , grid);

    }
};