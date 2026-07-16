class Solution {
public:

    const int INF = 1e9;

    // TC - O(2^m)
    // SC - O(m)
    int solveRECURSION(int i , int j , vector<vector<int>>& triangle){
        int m = triangle.size();

        if(i == m-1)
            return triangle[i][j];

        int down = triangle[i][j] + solveRECURSION(i + 1 , j , triangle);
        int diagonal = triangle[i][j] + solveRECURSION(i + 1 , j + 1 , triangle);

        return min(down , diagonal);
    }

    // TC - O(m^2)
    // SC - O(m^2) + O(m)
    int solveMEMOIZATION(int i , int j , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        int m = triangle.size();

        if(i == m-1)
            return triangle[i][j];

        if(dp[i][j] != INF)
            return dp[i][j];    

        int down = triangle[i][j] + solveMEMOIZATION(i + 1 , j , triangle , dp);
        int diagonal = triangle[i][j] + solveMEMOIZATION(i + 1 , j + 1 , triangle , dp);

        return dp[i][j] = min(down , diagonal);
    }

    // TC - O(m^2)
    // SC - O(m^2) 
    int solveTABULATION(vector<vector<int>>& triangle){
        int m = triangle.size();
        vector<vector<int>>dp(m , vector<int>(m , 0));

        for(int j = 0 ; j < m ; j++){
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i = m - 2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down , diagonal);
            }
        }

        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        return solveTABULATION(triangle);

        // int m = triangle.size();
        // vector<vector<int>>dp(m , vector<int>(m , INF));
        // return solveMEMOIZATION(0 , 0 , triangle , dp);

        // return solveRECURSION(0 , 0 , triangle);
        
    }
};