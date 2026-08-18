class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int, int> freq;

        // Count in how many windows each number appears
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            for (int x : seen) {
                freq[x]++;
            }
        }

        int ans = -1;

        // A number is valid if it appears in exactly one window
        for (auto &[x, count] : freq) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};