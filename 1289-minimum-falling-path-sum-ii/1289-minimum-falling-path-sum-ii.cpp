class Solution {
public:

    // TC - O(n^n)
    // SC - O(n) (recursion stack) TLE
    int solveRECURSION(vector<vector<int>>& matrix , int i , int j){

        int n = matrix.size();

        if(i == n - 1){
            return matrix[n - 1][j];
        }

        int ans = 1e9;

        for(int col = 0 ; col < n ; col++){
            if(col != j){
                ans = min(ans , matrix[i][j] + solveRECURSION(matrix , i + 1 , col));
            }
        }

        return ans;
    }

    // TC - O(n^3)
    // SC - O(n^2) + O(n)
    int solveMEMOIZATION(vector<vector<int>>& matrix , int i , int j , vector<vector<int>>& dp){

        int n = matrix.size();

        if(i == n - 1){
            return matrix[n - 1][j];
        }

        if(dp[i][j] != 1e9)
            return dp[i][j];

        int ans = 1e9;

        for(int col = 0 ; col < n ; col++){
            if(col != j){
                ans = min(ans , matrix[i][j] + solveMEMOIZATION(matrix , i + 1 , col , dp));
            }
        }
        return dp[i][j] = ans;
    }

    // TC - O(n^3)
    // SC - O(n^2)
    int solveTABULATION(vector<vector<int>>& matrix){

        int n = matrix.size();
        vector<vector<int>> dp(n , vector<int>(n , 0));

        // Base Case
        for(int j = 0 ; j < n ; j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        
        for(int i = n-2  ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int ans = 1e9;

                for(int col = 0 ; col < n ; col++){
                    if(col != j){
                        ans = min(ans , matrix[i][j] + dp[i + 1][col]);
                    }
                }

                dp[i][j] = ans;
            }
        }

        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            mini = min(mini , dp[0][i]);
        }

        return mini;
    }

    // TC - O(n^3)
    // SC - O(n)
    int solveSPACEOPTIMIZATION(vector<vector<int>>& matrix){

        int n = matrix.size();
        vector<int> curr(n);

        // Base Case
        for(int j = 0 ; j < n ; j++){
            curr[j] = matrix[n-1][j];
        }
        
        for(int i = n-2  ; i >= 0 ; i--)
        {
            vector<int> next(n);
            for(int j = n-1 ; j >=0 ; j--)
            {
                int ans = 1e9;

                for(int col = 0 ; col < n ; col++){
                    if(col != j){
                        ans = min(ans , matrix[i][j] + curr[col]);
                    }
                }

                next[j] = ans;
            }
            curr = next;
        }

        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            mini = min(mini , curr[i]);
        }

        return mini;
    } 

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n , vector<int>(n , 1e9));

        ans = min(ans , solveSPACEOPTIMIZATION(matrix));
        
        // ans = min(ans , solveTABULATION(matrix));

        // for(int j = 0 ; j < n ; j++){   
            
        //     ans = min(ans , solveMEMOIZATION(matrix , 0 , j , dp));
         
            // ans = min(ans , solveRECURSION(matrix , 0 , j));
        // }

        return ans;

    }
};