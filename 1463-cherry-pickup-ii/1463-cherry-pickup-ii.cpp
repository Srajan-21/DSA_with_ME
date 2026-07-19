class Solution {
public:

    int INF = -1e9;
    vector<int> dirs = {-1 , 0 , 1};

    // Time Complexity : O(m * n^2)
    // Space Complexity : O(m * n)
    int solveSPACE(int m , int  n , vector<vector<int>>& grid)
    {
        vector<vector<int>> front(n , vector<int>(n , INF));
        vector<vector<int>> curr(n , vector<int>(n , INF));

        for(int j1 = 0 ; j1 < n ; j1++)
        {
            for(int j2 = 0 ; j2 < n ; j2++)
            {
                front[j1][j2] = j1 == j2 ? grid[m - 1][j1] : grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for(int i = m - 2 ; i >= 0 ; i--)
        {
            for(int j1 = 0 ; j1 < n ; j1++)
            {
                for(int j2 = 0 ; j2 < n ; j2++)
                {
                    int maxi = INF;
                    
                    for(auto dj1 : dirs)
                    {
                        for(auto dj2 : dirs)
                        {
                            int value = 0;
                            value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            
                            if(j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                            {
                                value += front[j1 + dj1][j2 + dj2];
                                maxi = max(maxi , value);    
                            }
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][n-1];
    }

    // Time Complexity : O(m * n^2)
    // Space Complexity : O(m * n^2)
    int solveTABULATION(int m , int  n , vector<vector<int>>& grid)
    {
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(n , INF)));

        for(int j1 = 0 ; j1 < n ; j1++)
        {
            for(int j2 = 0 ; j2 < n ; j2++)
            {
                dp[m - 1][j1][j2] = j1 == j2 ? grid[m - 1][j1] : grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for(int i = m - 2 ; i >= 0 ; i--)
        {
            for(int j1 = 0 ; j1 < n ; j1++)
            {
                for(int j2 = 0 ; j2 < n ; j2++)
                {
                    int maxi = INF;
                    
                    for(auto dj1 : dirs)
                    {
                        for(auto dj2 : dirs)
                        {
                            int value = 0;
                            value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            
                            if(j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                            {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                                maxi = max(maxi , value);    
                            }
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][n-1];
    }

    // Time Complexity = O(m*n^2)
    // Space Complexity = O(m*n^2) + O(m)
    int solveMEMOIZATION(int i , int j1 , int j2 , int m , int n , vector<vector<int>>& grid , vector<vector<vector<int>>> &dp)
    {

        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return INF;

        if(i == m - 1)
        {
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != INF)
            return dp[i][j1][j2];

        int maxi = INF;
        
        for(auto dj1 : dirs){
            for(auto dj2 : dirs){
                int value = 0;

                if(j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solveMEMOIZATION(i + 1 , j1 + dj1 , j2 + dj2 , m , n , grid , dp);
                maxi = max(maxi , value);    
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    // Time Complexity = O(9^m)
    // Space Complexity = O(m)
    int solveRECURSION(int i , int j1 , int j2 , int m , int n , vector<vector<int>>& grid)
    {

        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return INF;

        if(i == m - 1)
        {
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        int maxi = INF;
        for(auto dj1 : dirs){
            for(auto dj2 : dirs){
                int value = 0;

                if(j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solveRECURSION(i + 1 , j1 + dj1 , j2 + dj2 , m , n , grid);
                maxi = max(maxi , value);    
            }
        }

        return maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        return solveSPACE(m , n , grid);

        // return solveTABULATION(m , n , grid);

        // vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(n , INF)));
        // return solveMEMOIZATION(0 , 0 , n - 1 , m , n , grid , dp);

        // return solveRECURSION(0 , 0 , n - 1 , m , n , grid);
        
    }
};