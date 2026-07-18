class Solution {
public:

    // TC - O(n^3)
    // SC - O(n^3)
    int solveTABULATION(vector<vector<int>>& grid)
    {

        int n = grid.size();
        vector<vector<vector<int>>> dp(2* n - 1 , vector<vector<int>>(n , vector<int>(n , -1e9)));

        // Base case
        dp[2 * n - 2][n - 1][n - 1] = grid[n-1][n-1];

        for(int step = 2 * n - 3 ; step >= 0 ; step--)
        {
            for (int r1 = max(0, step - (n - 1)) ; r1 <= min(n - 1, step) ; r1++)
            {
                int c1 = step - r1;
                for (int r2 = max(0, step - (n - 1)) ; r2 <= min(n - 1, step) ; r2++)
                    {
                    int c2 = step - r2;

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
                        continue;

                    int current = grid[r1][c1];

                    if (r1 != r2 || c1 != c2)
                        current += grid[r2][c2];
                    
                    int DD = -1e9;
                    int DR = -1e9;
                    int RD = -1e9;
                    int RR = -1e9;

                    if (r1 + 1 < n && r2 + 1 < n)
                        DD = dp[step + 1][r1 + 1][r2 + 1];

                    if (r1 + 1 < n && c2 + 1 < n)
                        DR = dp[step + 1][r1 + 1][r2];

                    if (c1 + 1 < n && r2 + 1 < n)
                        RD = dp[step + 1][r1][r2 + 1];

                    if (c1 + 1 < n && c2 + 1 < n)
                        RR = dp[step + 1][r1][r2];

                    int best = max({DD, DR, RD, RR});

                    if(best != -1e9)
                        dp[step][r1][r2] = current + best;
                }
            }
        }

        return max(0 , dp[0][0][0]);     
    }

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

        return solveTABULATION(grid);

        // return max(0 , solveMEMOIZATION(0 , 0 , 0 , grid , dp));

        // return max(0 , solveRECURSION(0 , 0 , 0 , grid));
    }
};