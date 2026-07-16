class Solution {
public:

    // TC - O(3^n)
    // SC - O(n) (recursion stack) TLE
    int solveRECURSION(vector<vector<int>>& matrix , int i , int j){

        int n = matrix.size();

        if(j >= n || j < 0){
            return 1e9;
        }

        if(i == n - 1){
            return matrix[n - 1][j];
        }

        int down = matrix[i][j] + solveRECURSION(matrix , i + 1 , j);
        int leftDg = matrix[i][j] + solveRECURSION(matrix , i + 1 , j - 1);
        int rightDg = matrix[i][j] + solveRECURSION(matrix , i + 1 , j + 1);

        return min(down , min(leftDg , rightDg));
    }

    // TC - O(n^2)
    // SC - O(n^2) + O(n) (recursion stack)
    int solveMEMOIZATION(vector<vector<int>>& matrix , int i , int j , vector<vector<int>>& dp){

        int n = matrix.size();

        if(j >= n || j < 0){
            return 1e9;
        }

        if(i == n - 1){
            return matrix[n - 1][j];
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = matrix[i][j] + solveMEMOIZATION(matrix , i + 1 , j , dp);
        int leftDg = matrix[i][j] + solveMEMOIZATION(matrix , i + 1 , j - 1 , dp);
        int rightDg = matrix[i][j] + solveMEMOIZATION(matrix , i + 1 , j + 1 , dp);

        return dp[i][j] = min(down , min(leftDg , rightDg));
    }

    // TC - O(n^2)
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
            for(int j = n-1 ; j >=0 ; j--)
            {
                int leftDg = 1e9 , rightDg = 1e9;
                int up = matrix[i][j] + dp[i + 1][j];

                if(j - 1 >= 0)
                    leftDg = matrix[i][j] + dp[i + 1][j - 1];

                if(j + 1 < n)
                    rightDg = matrix[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(up , min(leftDg , rightDg));
            }
        }

        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            mini = min(mini , dp[0][i]);
        }

        return mini;
 
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n , vector<int>(n , -1));

        ans = min(ans , solveTABULATION(matrix));

        // for(int j = 0 ; j < n ; j++){
            // ans = min(ans , solveMEMOIZATION(matrix , 0 , j , dp));
            // ans = min(ans , solveRECURSION(matrix , 0 , j));
        // }

        return ans;

    }
};