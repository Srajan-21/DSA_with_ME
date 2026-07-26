class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size();
        int mx1 = INT_MIN , mx2 = INT_MIN , mx3 = INT_MIN;
        int mi1 = INT_MAX , mi2 = INT_MAX;

        for(auto x : nums)
        {
            if(x >= mx1)
            {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            }
            else if(x >= mx2)
            {
                mx3 = mx2;
                mx2 = x;
            }
            else if(x >= mx3)
            {
                mx3 = x;
            }

            if(x <= mi1)
            {
                mi2 = mi1;
                mi1 = x;
            }
            else if(x <= mi2)
            {
                mi2 = x;
            }
        }

        return max(mx1 * mx2 * mx3 , mx1 * mi1 * mi2);


        // sort(nums.begin() , nums.end());
        // for(auto i : nums)cout<<i<<" ";
        // return max(nums[n-1] * nums[n-2] * nums[n-3] , nums[0] * nums[1] * nums[n-1]);

    }
};