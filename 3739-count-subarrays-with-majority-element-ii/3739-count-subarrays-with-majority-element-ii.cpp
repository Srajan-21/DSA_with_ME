class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long> freq(2 * n + 3, 0);

        int offset = n + 1;
        int balance = offset;

        freq[balance] = 1;

        long long ans = 0;
        long long sum = 0;

        for (int x : nums) {
            if (x == target) {
                sum += freq[balance];
                balance++;
            } else {
                balance--;
                sum -= freq[balance];
            }

            freq[balance]++;
            ans += sum;
        }

        return ans;
    }
};