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

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n , vector<int>(n , 1e9));

        for(int j = 0 ; j < n ; j++){   
            
            ans = min(ans , solveMEMOIZATION(matrix , 0 , j , dp));
         
            // ans = min(ans , solveRECURSION(matrix , 0 , j));
        }

        return ans;

    }
};