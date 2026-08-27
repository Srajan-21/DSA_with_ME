class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // If we cannot use target[i], we need to make
            // the answer greater at this position or earlier.
            if (cnt[x] == 0) {
                
                // Try a character greater than target[i]
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        string ans = target.substr(0, i);
                        ans += char('a' + c);

                        cnt[c]--;

                        // Put remaining characters in smallest order
                        for (int j = 0; j < 26; j++) {
                            ans += string(cnt[j], char('a' + j));
                        }

                        return ans;
                    }
                }

                // Cannot make it greater here,
                // so we must backtrack.
                break;
            }

            cnt[x]--;
        }

        // Backtrack from right to left
        cnt.assign(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; i--) {
            // Characters before i must exactly match target
            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (cnt[c] == 0) {
                    break;
                }

                cnt[c]--;
            }

            // Check whether prefix [0...i-1] is possible
            bool possible = true;

            for (int j = 0; j < i; j++) {
                // Reconstructing counts is easier, so reset below
            }

            // Recalculate remaining characters
            cnt.assign(26, 0);
            for (char c : s) {
                cnt[c - 'a']++;
            }

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (cnt[c] == 0) {
                    possible = false;
                    break;
                }

                cnt[c]--;
            }

            if (!possible)
                continue;

            int x = target[i] - 'a';

            // Find smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    cnt[c]--;

                    // Smallest possible suffix
                    for (int j = 0; j < 26; j++) {
                        ans += string(cnt[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};