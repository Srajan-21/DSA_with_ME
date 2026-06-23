class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m), down(m);
        vector<int> prefixDown(m), suffixUp(m);
        vector<int> newUp(m), newDown(m);

        // Length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            prefixDown[0] = down[0];
            for (int i = 1; i < m; i++) {
                prefixDown[i] = (prefixDown[i - 1] + down[i]) % MOD;
            }

            suffixUp[m - 1] = up[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                suffixUp[i] = (suffixUp[i + 1] + up[i]) % MOD;
            }

            fill(newUp.begin(), newUp.end(), 0);
            fill(newDown.begin(), newDown.end(), 0);

            for (int i = 0; i < m; i++) {
                if (i > 0)
                    newUp[i] = prefixDown[i - 1];

                if (i + 1 < m)
                    newDown[i] = suffixUp[i + 1];
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};
