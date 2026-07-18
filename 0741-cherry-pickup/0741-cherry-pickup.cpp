class Solution {
public:

    // TC - O(n^3)
    // SC - O(n^3)
    int solveMEMOIZATION(int r1 , int c1 , int r2 , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp)
    {

        int c2 = r1 + c1 - r2;
        int n = grid.size();

        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n)
            return -1e9;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if(r1 == n-1 && c1 == n-1)
            return grid[n-1][n-1];

        if(dp[r1][c1][r2] != INT_MIN)
            return dp[r1][c1][r2];

        int DD = solveMEMOIZATION(r1 + 1 , c1 , r2 + 1 , grid , dp);
        int DR = solveMEMOIZATION(r1 + 1 , c1 , r2 , grid , dp);
        int RD = solveMEMOIZATION(r1  , c1 + 1 , r2 + 1 , grid , dp);
        int RR = solveMEMOIZATION(r1 , c1 + 1 , r2 , grid , dp);

        int maxi = max(DD , max(DR , max(RD , RR)));
        if(maxi == -1e9)
            return dp[r1][c1][r2] = -1e9;

        return dp[r1][c1][r2] = r1 == r2 && c1 == c2 ? grid[r1][c1] + maxi : grid[r1][c1] + grid[r2][c2] + maxi;        
    }

    // TC - O(16^n) TLE
    // SC - O(n)
    int solveRECURSION(int r1 , int c1 , int r2 , vector<vector<int>>& grid)
    {

        int c2 = r1 + c1 - r2;
        int n = grid.size();

        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n)
            return -1e9;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if(r1 == n-1 && c1 == n-1)
            return grid[n-1][n-1];

        int DD = solveRECURSION(r1 + 1 , c1 , r2 + 1 , grid);
        int DR = solveRECURSION(r1 + 1 , c1 , r2 , grid);
        int RD = solveRECURSION(r1  , c1 + 1 , r2 + 1 , grid);
        int RR = solveRECURSION(r1 , c1 + 1 , r2 , grid);

        int maxi = max(DD , max(DR , max(RD , RR)));
        if(maxi == -1e9)
            return -1e9;

        return r1 == r2 && c1 == c2 ? grid[r1][c1] + maxi : grid[r1][c1] + grid[r2][c2] + maxi;        
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n =grid.size();

        vector<vector<vector<int>>> dp(n , vector<vector<int>>(n , vector<int>(n , INT_MIN)));

        if(grid[0][0] == -1 || grid[n-1][n-1] == -1)
            return 0;

        return max(0 , solveMEMOIZATION(0 , 0 , 0 , grid , dp));

        // return max(0 , solveRECURSION(0 , 0 , 0 , grid));
    }
};