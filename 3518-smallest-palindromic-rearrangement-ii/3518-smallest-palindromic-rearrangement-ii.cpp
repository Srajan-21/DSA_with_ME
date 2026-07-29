class Solution {
public:

    long long capped_comb(int L, int c) {
        c = min(c, L - c);
        if (c == 0) return 1;
        long long res = 1;
        for (int i = 0; i < c; ++i) {
            res = res * (L - i) / (i + 1);
            if (res > 1000000) {
                return 1000001;
            }
        }
        return res;
    }

    long long get_P(const vector<int>& counts, int L, long long k_limit) {
        long long P = 1;
        for (int c : counts) {
            if (c > 0) {
                long long comb = capped_comb(L, c);
                P *= comb;
                if (P >= k_limit) {
                    return k_limit;
                }
                L -= c;
            }
        }
        return P;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        string mid = "";
        vector<int> half_counts(26, 0);
        int rem_L = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                mid += (char)('a' + i);
            }
            half_counts[i] = freq[i] / 2;
            rem_L += half_counts[i];
        }
        
        if (get_P(half_counts, rem_L, k) < k) {
            return "";
        }
        
        string half_str = "";
        
        for (int step = 0; step < rem_L; ++step) {
            for (int i = 0; i < 26; ++i) {
                if (half_counts[i] > 0) {
                    half_counts[i]--;
                    
                    long long P = get_P(half_counts, rem_L - 1 - step, k);
                    
                    if (k <= P) {
                        half_str += (char)('a' + i);
                        break; 
                    } else {
                        k -= P;
                        half_counts[i]++;
                    }
                }
            }
        }
        
        string rev_half = half_str;
        reverse(rev_half.begin(), rev_half.end());
        
        return half_str + mid + rev_half;
    }
};