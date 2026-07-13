#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

long long int countDerangementsMemoization(int n , vector<long long int> &dp){
    
    if(n == 1) return 0;
    if(n == 2)return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = (((n-1) % MOD) * ((countDerangementsMemoization(n - 1, dp) % MOD) +  (countDerangementsMemoization(n - 2, dp) % MOD)) ) % MOD;

    return dp[n];
}

long long int countDerangementsTabulation(int n){
    vector<long long int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){

        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        dp[i] = (((i-1) % MOD) * sum) % MOD;

        // dp[i] = (((i-1) % MOD) * ((dp[i - 1] % MOD) +  (dp[i - 2] % MOD)) ) % MOD;
    }

    return dp[n];
}

long long int countDerangementsSpaceOptimized(int n){

    if(n == 1) return 0;
    if(n == 2) return 1;

    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i = 3; i <= n; i++){

        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;
        long long int curr = (((i-1) % MOD) * sum) % MOD;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int countDerangementsRecursion(int n){

    if(n == 1) return 0;
    if(n == 2)return 1;

    int ans = (((n-1) % MOD) * ((countDerangementsRecursion(n - 1) % MOD) +  (countDerangementsRecursion(n - 2) % MOD)) ) % MOD;

    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<long long int> dp(n + 1, -1);

    // cout << countDerangementsRecursion(n) << endl;
    // cout<< countDerangementsMemoization(n, dp) << endl;
    // cout << countDerangementsTabulation(n) << endl;
    cout << countDerangementsSpaceOptimized(n) << endl;

    return 0;
}