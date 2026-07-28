class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1) , right(n + 1);

        // All subset sums for left half
        for(int m = 0 ; m < (1 << n) ; m++)
        {
            int sum = 0 , count = 0;

            for(int i = 0 ; i < n ; i++)
            {
                if(m & (1 << i))
                {
                    sum += nums[i];
                    count++;
                }
            }
            left[count].push_back(sum);
        }

        // All subset sums for right half
        for(int m = 0 ; m < (1 << n) ; m++)
        {
            int sum = 0 , count = 0;

            for(int i = 0 ; i < n ; i++)
            {
                if(m & (1 << i))
                {
                    sum += nums[n + i];
                    count++;
                }
            }
            right[count].push_back(sum);
        }

        // Sort every grp of right subset sums
        for(int i = 0 ; i <= n ; i++)
            sort(right[i].begin() , right[i].end());

        int total = accumulate(nums.begin() , nums.end() , 0);
        int ans = INT_MAX;

        for(int k = 0 ; k <= n ; k++)
        {
            auto &l = left[k];
            auto &r = right[n - k];

            for(int s1 : l){
                double target = (total / 2.0) - s1;

                auto it = lower_bound(r.begin() , r.end() , target);

                if(it != r.end())
                {
                    int s2 = *it;
                    int c = s1 + s2;
                    ans = min(ans , abs(total - 2 * c));
                }

                if(it != r.begin())
                {
                    --it;
                    int s2 = *it;
                    int c = s1 + s2;
                    ans = min(ans , abs(total - 2 * c));
                }
            }
        }

        return ans;






        // Solution is correct but the constraint dont match this solution
        // int n = nums.size();
        // int totSum = 0;

        // for(int i = 0 ; i < n ; i++)
        //     totSum += nums[i];

        // int k = totSum;
        // vector<vector<bool>> dp(n , vector<bool>(k + 1 , 0));

        // for(int i = 0 ; i < n ; i++)
        //     dp[i][0] = true;

        // if(nums[0] <= k)
        //     dp[0][nums[0]] = true;

        // for(int ind = 1 ; ind < n ; ind++)
        // {
        //     for(int target = 1 ; target <= k ; target++)
        //     {
        //         bool notTake = dp[ind - 1][target];
        //         bool take = false;

        //         if(nums[ind] <= target)
        //             take = dp[ind - 1][target - nums[ind]];

        //         dp[ind][target] = take | notTake;
        //     }
        // }

        // int mini = 1e9;
        // for(int s1 = 0 ; s1 <= totSum / 2 ; s1++)
        // {
        //     if(dp[n - 1][s1])
        //         mini = min(mini , abs(totSum - 2*s1));
        // }

        // return mini;
    }
};