class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> solve = [&](int l, int r) -> int {

            // Only one stone
            if (l == r)
                return 0;

            if (dp[l][r] != -1)
                return dp[l][r];

            int ans = 0;

            for (int k = l; k < r; k++) {

                int leftSum = prefix[k + 1] - prefix[l];
                int rightSum = prefix[r + 1] - prefix[k + 1];

                if (leftSum < rightSum) {

                    // Right is discarded
                    // Alice keeps LEFT
                    ans = max(
                        ans,
                        leftSum + solve(l, k)
                    );

                }
                else if (leftSum > rightSum) {

                    // Left is discarded
                    // Alice keeps RIGHT
                    ans = max(
                        ans,
                        rightSum + solve(k + 1, r)
                    );

                }
                else {

                    // Equal → Alice chooses either
                    ans = max({
                        ans,
                        leftSum + solve(l, k),
                        rightSum + solve(k + 1, r)
                    });
                }
            }

            return dp[l][r] = ans;
        };

        return solve(0, n - 1);
    }
};