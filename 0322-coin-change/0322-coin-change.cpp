class Solution {
public:

    // ṬLE
    int solveRec(vector<int>& coins , int x){
        if(x==0)return 0;
        if(x<0)return INT_MAX;

        int mini = INT_MAX;
        for(int i =0 ; i<coins.size(); i++){
            int ans = solveRec(coins,x-coins[i]);
            if(ans!=INT_MAX)
                mini = min(mini , 1+ans);
        }
        return mini;
    }

    // Rec+memo
    int solveMemo(vector<int> &coins , int x , vector<int>&dp){
        if(x==0)return 0;
        if(x<0)return INT_MAX;
        if(dp[x]!=-1)return dp[x];
        int mini = INT_MAX;

        for(int i = 0 ; i < coins.size() ; i++){
            int ans = solveMemo(coins , x-coins[i],dp);
            if(ans!=INT_MAX)mini=min(mini,1+ans);
        }
        dp[x] = mini;
        return mini;
    }

    // Tabular
    int solveTab(vector<int> &coins , int x){
        vector<int> dp(x+1 , INT_MAX);
        dp[0] = 0;
        
        for(int i = 1 ; i <= x ; i++){
            for(int j = 0 ; j < coins.size() ; j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i] , 1+dp[i-coins[j]]);
                }
            }
        }
        return dp[x] == INT_MAX ? -1 : dp[x];
    }

    int coinChange(vector<int>& coins, int amount) {
        // TLE
        // int ans = solveRec(coins,amount);
        // if(ans == INT_MAX)return -1;
        // return ans;

        //Rec + memo TC - O(amount*n) SC-O(amount)
        // vector<int> dp(amount+1 , -1);
        // int ans = solveMemo(coins,amount,dp);
        // return ans == INT_MAX ? -1 : ans;        

        // Tab - TC - O(amount*n) SC-O(amount)
        return solveTab(coins,amount);
    }
};