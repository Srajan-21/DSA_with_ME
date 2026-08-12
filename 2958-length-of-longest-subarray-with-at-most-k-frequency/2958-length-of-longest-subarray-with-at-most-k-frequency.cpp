class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int l = 0 , ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;

            while(freq[nums[i]] > k){
                freq[nums[l]]--;
                l++;
            }

            ans = max(ans , i - l + 1);
        }
        return ans;
    }
};