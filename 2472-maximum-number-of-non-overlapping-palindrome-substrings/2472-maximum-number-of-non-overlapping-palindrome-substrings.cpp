class Solution {
public:

    bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int i = 0;
        
        while (i <= n - k) {
            if (isPalin(s, i, i + k - 1)) {
                count++;
                i += k;
            }
            else if (i + k < n && isPalin(s, i, i + k)) {
                count++;
                i += k + 1;
            }
            else {
                i++;
            }
        }
        
        return count;
    }
};