class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        
        int mx = *max_element(nums.begin() , nums.end());
        
        vector<int> freq(mx + 1);

        for(int x : nums){
            freq[x]++;
        }

        vector<int>countDiv(mx + 1);

        // count nums div by d
        for(int d = 1 ; d <= mx ; d++)
        {
            for(int mul = d ; mul <= mx ; mul += d)
            {
                countDiv[d] += freq[mul];
            }
        }

        vector<long long> exact(mx + 1);
        for(int d = mx ; d >= 1 ; d--)
        {
            long long cnt = countDiv[d];
            exact[d] = cnt * (cnt - 1) / 2;

            for(int mul = 2 * d ; mul <= mx ; mul += d){
                exact[d] -= exact[mul];
            }
        }

        vector<long long> prefix;
        long long sum = 0;

        for(int d = 1 ; d <= mx ; d++)
        {
            sum += exact[d];
            prefix.push_back(sum);
        }

        vector<int> ans;
        for(long long q : queries)
        {
            int index = lower_bound(prefix.begin() , prefix.end() , q + 1) - prefix.begin();

            ans.push_back(index + 1);
        }

        return ans;
    }
};