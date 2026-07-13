#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

int add(int a , int b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

int multiply(int a , int b){
    return (1LL * (a % MOD) * (b % MOD)) % MOD;
}

// TLE 
// TC: O(2^n) , SC: O(n)
int solveRecursion(int n , int k){
    
    if(n == 0) return 1;
    if(n == 1) return k;
    if(n == 2) return add(k , multiply(k , (k - 1)));

    int ans = multiply(k-1 , add(solveRecursion(n - 1 , k) , solveRecursion(n - 2 , k)));

    return ans;
}

// TC: O(n) , SC: O(n) + O(n) for recursion stack
int solveMemoization(int n , int k , vector<int> &dp){
    
    if(n == 0) return 1;
    if(n == 1) return k;
    if(n == 2) return add(k , multiply(k , (k - 1)));

    if(dp[n] != -1) return dp[n];

    dp[n] = multiply(k-1 , add(solveMemoization(n - 1 , k , dp) , solveMemoization(n - 2 , k , dp)));

    return dp[n];
}

// TC: O(n) , SC: O(n)
int solveTabulation(int n , int k){
    vector<int> dp(n + 1 , -1);
    dp[0] = 1;
    dp[1] = k;
    dp[2] = add(k , multiply(k , (k - 1)));

    for(int i = 3; i <= n; i++){
        dp[i] = multiply(k-1 , add(dp[i - 1] , dp[i - 2]));
    }

    return dp[n];
}

// TC: O(n) , SC: O(1)
int solveSpaceOptimized(int n , int k){
    if(n == 0) return 1;
    if(n == 1) return k;
    if(n == 2) return add(k , multiply(k , (k - 1)));

    int prev2 = k;
    int prev1 = add(k , multiply(k , (k - 1)));;
    int curr;

    for(int i = 3; i <= n; i++){
        curr = multiply(k-1 , add(prev1 , prev2));
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main(){
    int n , k;
    cin >> n >> k;
    vector<int> dp(n + 1 , -1);

    // cout << solveRecursion(n , k) << endl;
    // cout << solveMemoization(n , k , dp) << endl;
    // cout << solveTabulation(n , k) << endl;
    cout << solveSpaceOptimized(n , k) << endl;

    return 0;
}