#include <bits/stdc++.h>
using namespace std;

// TLE
int solveRecursion(vector<int>& nums , int n){

// Base case
    if(n < 0)return 0;
    if(n == 0)return max(0,nums[0]);

    int including = solveRecursion(nums , n-2) + nums[n];
    int excluding = solveRecursion(nums , n-1) + 0;

    return max(including , excluding);
}

// TC - O(n) SC - O(n)+O(n)
int solveMemoization(vector<int>& nums , int n , vector<int>& dp){

    // Base case
    if(n < 0)return 0;
    if(n == 0)return max(0,nums[0]);

    if(dp[n] != -1)return dp[n];

    int including = solveMemoization(nums , n-2 , dp) + nums[n];
    int excluding = solveMemoization(nums , n-1 , dp) + 0;

    dp[n] = max(including , excluding);
    return dp[n];
}

// TC - O(n) SC - O(n)
int solveTabular(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = max(0, nums[0]);

    for(int i = 1 ; i < n ; i++){
        int including = (i >= 2 ? dp[i-2] : 0) + nums[i];
        int excluding = dp[i-1] + 0;

        dp[i] = max(including , excluding);
    }
    return dp[n-1];
}

// TC - O(n) SC - O(1)
int solveSpaceOptimization(vector<int>& nums){
    int n = nums.size();

    int prev2 = 0;
    int prev1 = max(0,nums[0]);

    for(int i = 1 ; i < n ; i++){
        int including = prev2 + nums[i];
        int excluding = prev1 + 0;

        int ans = max(including , excluding);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumSumSubsequence(vector<int>& nums) {
    int n = nums.size();
    

    if (n == 0) return 0;

    long long ans = 0;

    
        vector<int> dp(n, -1);
        ans = (ans + solveRecursion(nums, n - 1)) ;

        // Or use one of these:
        // ans = (ans + solveMemoization(nums, n - 1, dp)) ;
        // ans = (ans + solveTabular(nums)) ;
        // ans = (ans + solveSpaceOptimization(nums)) ;
    

    return (int)ans;
}

int main() {
    vector<int> nums = {-3, -2};
    int result = maximumSumSubsequence(nums);
    cout << "Maximum sum of non-adjacent elements: " << result << endl;
    return 0;
}