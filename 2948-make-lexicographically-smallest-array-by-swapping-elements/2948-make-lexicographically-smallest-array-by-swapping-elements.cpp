class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            int j = i + 1;

            // Find the connected group
            while (j < n && a[j].first - a[j - 1].first <= limit) {
                j++;
            }

            vector<int> indices;

            for (int k = i; k < j; k++) {
                indices.push_back(a[k].second);
            }

            sort(indices.begin(), indices.end());

            // a[i..j-1] values are already sorted
            for (int k = 0; k < j - i; k++) {
                ans[indices[k]] = a[i + k].first;
            }

            i = j;
        }

        return ans;
    }
};