#include <bits/stdc++.h>
using namespace std;

    const int INF = 1e9;

    // RECURSION 
    // Time Complexity = O(2^n)
    // Space Complexity = O(n)
    int solveRECURSION(vector<int>& weight , vector<int>& value , int index , int W){

        if(index == 0){
            if(weight[0] <= W)
                return value[0];
            else 
                return 0;
        }

        int include = 0;
        if(weight[index] <= W)
            include = value[index] + solveRECURSION(weight , value , index - 1 , W - weight[index]);

        int exclude = 0 + solveRECURSION(weight , value , index - 1 , W);       

        return max(include , exclude);
    }

    // MEMOIZATION
    // TC - O(n^2)
    // SC - O(n^2)DP + O(n)recursion stack
    int solveMEMOIZATION(vector<int>& weight , vector<int>& value , int index , int capacity ,  vector<vector<int>> &dp){

        if(index == 0){
            if(weight[0] <= capacity)
                return value[0];
            else 
                return 0;
        }

        if(dp[index][capacity] != -1)
            return dp[index][capacity];

        int include = 0;
        if(weight[index] <= capacity)
            include = value[index] + solveMEMOIZATION(weight , value , index - 1 , capacity - weight[index] , dp);

        int exclude = 0 + solveMEMOIZATION(weight , value , index - 1 , capacity , dp);

        dp[index][capacity] = max(include , exclude);        

        return dp[index][capacity];
    }

    // TABULATION
    // TC - O(n^2)
    // SC - O(n^2)DP 
    int solveTABULATION(vector<int>& weight , vector<int>& value , int n , int capacity){
        vector<vector<int>> dp(n + 1 ,vector<int>(capacity + 1 , 0));

        for(int w = weight[0] ; w <= capacity ; w++){
            if(weight[0] <= w)
                dp[0][w] = value[0];
            else 
                dp[0][w] = 0;
        }

        for(int index = 1 ; index < n ; index++){
            for(int w = 0 ; w <= capacity ; w++){

                int include = 0;
                if(weight[index] <= w)
                    include = value[index] + dp[index - 1][w - weight[index]];
                int exclude = 0 + dp[index - 1][w];
                dp[index][w] = max(include , exclude);
            }
        }

        return dp[n-1][capacity];
    }

    // SPACE OPTIMIZATION
    // TC - O(n^2)
    // SC - O(n) 
    int solveSPACEOPTIMIZATION(vector<int>& weight , vector<int>& value , int n , int capacity){

        vector<int> prev(capacity + 1 , 0);
        vector<int> curr(capacity + 1 , 0);

        for(int w = weight[0] ; w <= capacity ; w++){
            if(weight[0] <= w)
                prev[w] = value[0];
            else 
                prev[w] = 0;
        }

        for(int index = 1 ; index < n ; index++){
            for(int w = 0 ; w <= capacity ; w++){

                int include = 0;
                if(weight[index] <= w)
                    include = value[index] + prev[w - weight[index]];
                int exclude = 0 + prev[w];
                curr[w] = max(include , exclude);
            }
            prev = curr;
        }

        return prev[capacity];
    }

    int main(){
        

        vector<int> weight{1, 2, 3, 2};
        vector<int> value{4, 5, 6, 3} ;

        int n = weight.size();
        int capacity = 5;

        // RECURSION
        cout << "RECURSION          : ";
        cout << solveRECURSION(weight , value , n - 1 , capacity) << endl;

        // MEMOIZATION
        cout << "MEMOIZATION        : ";
        vector<vector<int>> dp(n + 1 ,vector<int>(capacity + 1 , -1));
        cout << solveMEMOIZATION(weight , value , n - 1 , capacity , dp) << endl;

        // TABULATION
        cout << "TABULATION         : ";
        cout << solveTABULATION(weight , value , n , capacity) << endl;

        // SPACE OPTIMIZATION
        cout << "SPACE OPTIMIZATION : ";
        cout << solveSPACEOPTIMIZATION(weight , value , n , capacity) << endl;

    }