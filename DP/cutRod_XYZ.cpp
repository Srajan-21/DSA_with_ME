#include<algorithm>
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solveRecursion(int n , int x , int y , int z){
    if(n == 0)return 0;
    if(n < 0)return INT_MIN;

    int a = solveRecursion(n - x , x , y , z) + 1;
    int b = solveRecursion(n - y , x , y , z) + 1;
    int c = solveRecursion(n - z , x , y , z) + 1;

    return max(a , max(b , c));
}

int solveMemoization(int n , int x , int y , int z , vector<int> &dp){
    if(n == 0)return 0;
    if(n < 0)return INT_MIN;

    if(dp[n] != -1)return dp[n];

    int a = solveMemoization(n-x , x, y , z , dp) + 1;
    int b = solveMemoization(n-y , x , y , z , dp) + 1;
    int c = solveMemoization(n-z , x , y , z , dp) + 1;

    return dp[n] = max(a , max(b , c));
}

int solveTabulation(int n , int x , int y , int z){

    vector<int>dp(n+1 , -1);
    dp[0] = 0;

    for(int i = 1 ; i <= n ; i++){
        if(i-x >= 0 && dp[i-x] != -1)
            dp[i] = max(dp[i] , dp[i-x] + 1);
        if(i-y >= 0 && dp[i-y] != -1)
            dp[i] = max(dp[i] , dp[i-y] + 1);
        if(i-z >= 0 && dp[i-z] != -1)
            dp[i] = max(dp[i] , dp[i-z] + 1);
    }

    return dp[n] < 0 ? 0 : dp[n];
}

int cutSegments(int n , int x , int y , int z){
    // Recursion
    // TC = O(3^n) , SC = O(n)
    // int ans = solveRecursion(n , x , y , z);

    // Memoization
    // TC = O(n) , SC = O(n) + O(n)
    // vector<int> dp(n+1 , -1);
    // int ans = solveMemoization(n , x , y , z , dp);

    // Tabulation
    // TC = O(n) , SC = O(n)
    int ans = solveTabulation(n , x , y , z);

    // No space optimization because we need to store the previous values to calculate the current value.

    return ans < 0 ? 0 : ans;
}

int main(){
    int n , x , y , z;
    cin >> n >> x >> y >> z;
    cout << cutSegments(n , x , y , z) << endl;
    return 0;
}