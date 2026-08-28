class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int h = n / 2;
        
        int count[26] = {};
        for (char c : s) count[c - 'a']++;
        
        int oddCount = 0;
        for (int i = 0; i < 26; i++) if (count[i] % 2) oddCount++;
        
        if (n % 2 == 0 && oddCount > 0) return "";
        if (n % 2 == 1 && oddCount != 1) return "";
        
        int mid = -1;
        if (n % 2 == 1) {
            for (int i = 0; i < 26; i++)
                if (count[i] % 2) { mid = i; break; }
        }
        
        int avail[26];
        for (int i = 0; i < 26; i++) avail[i] = count[i] / 2;
        
        auto build = [&](vector<int>& fh) -> string {
            string res(n, ' ');
            for (int i = 0; i < h; i++) {
                res[i] = 'a' + fh[i];
                res[n - 1 - i] = 'a' + fh[i];
            }
            if (mid >= 0) res[h] = 'a' + mid;
            return res;
        };
        
        // Greedily match target's first h characters
        vector<int> prefix;
        for (int i = 0; i < h; i++) {
            int c = target[i] - 'a';
            if (avail[c] > 0) {
                avail[c]--;
                prefix.push_back(c);
            } else {
                break;
            }
        }
        
        int mm = prefix.size();
        
        // If fully matched, check if palindrome already > target
        if (mm == h) {
            string pal = build(prefix);
            if (pal > target) return pal;
        }
        
        // Try divergence from rightmost possible position
        int start = (mm == h) ? h - 1 : mm;
        
        for (int d = start; d >= 0; d--) {
            // Restore characters after position d
            while ((int)prefix.size() > d) {
                avail[prefix.back()]++;
                prefix.pop_back();
            }
            
            int td = target[d] - 'a';
            int chosen = -1;
            for (int c = td + 1; c < 26; c++) {
                if (avail[c] > 0) { chosen = c; break; }
            }
            
            if (chosen >= 0) {
                avail[chosen]--;
                vector<int> fh(prefix);
                fh.push_back(chosen);
                // Fill remaining with smallest available
                for (int j = d + 1; j < h; j++) {
                    for (int c = 0; c < 26; c++) {
                        if (avail[c] > 0) {
                            fh.push_back(c);
                            avail[c]--;
                            break;
                        }
                    }
                }
                return build(fh);
            }
        }
        
        return "";
    }
};