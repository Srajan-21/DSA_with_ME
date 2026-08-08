class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = maximum number of characters of word2
        // that can be matched exactly using word1[i...n-1]
        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;

        int i = 0;
        j = 0;
        bool mismatchUsed = false;

        while (j < m) {

            while (i < n) {

                // Exact match
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    j++;
                    break;
                }

                // Use our one allowed mismatch
                // if the remaining characters can still
                // be matched exactly.
                if (!mismatchUsed &&
                    suf[i + 1] >= m - j - 1) {

                    ans.push_back(i);
                    mismatchUsed = true;
                    i++;
                    j++;
                    break;
                }

                i++;
            }

            // Couldn't find a valid index
            if (i == n && j < m)
                return {};
        }

        return ans;
    }
};