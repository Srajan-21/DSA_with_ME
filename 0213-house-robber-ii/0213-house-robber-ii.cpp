class Solution {
public:

    // TLE
    int rec(vector<int>& nums , int n){
        if(n < 0)return 0;
        int inc = rec(nums , n-2) + nums[n];
        int exc = rec(nums , n-1);

        return max(inc , exc);
    }

    // TC - O(n) SC - O(n)+O(n)
    int memo(vector<int>& nums , vector<int>&dp , int n){

        if(n < 0)return 0;
        if(dp[n] != -1)return dp[n];

        int inc = memo(nums , dp , n-2) + nums[n];
        int exc = memo(nums , dp , n-1);

        dp[n] = max(inc , exc);
        return dp[n];        
    }

    int rob(vector<int>& nums) {
        vector<int> first , second;
        int n = nums.size();
        vector<int> dp1(n-1 , -1);
        vector<int> dp2(n-1 , -1);

        if(n == 1)return nums[0];

        for(int i = 0 ; i < n ; i++){
            if(i != n-1)first.push_back(nums[i]);
            if (i != 0)second.push_back(nums[i]);
        }

        return max(memo(first , dp1 , n-2) , memo(second , dp2 , n-2));
        // return max(rec(first , n-2) , rec(second , n-2));
    }
};