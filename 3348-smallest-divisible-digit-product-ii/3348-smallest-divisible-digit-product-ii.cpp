#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        // 1. Factorize the target `t`
        long long temp = t;
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        
        while (temp % 2 == 0) { c2++; temp /= 2; }
        while (temp % 3 == 0) { c3++; temp /= 3; }
        while (temp % 5 == 0) { c5++; temp /= 5; }
        while (temp % 7 == 0) { c7++; temp /= 7; }
        
        // If t has any prime factors other than 2, 3, 5, 7, it's definitively impossible.
        if (temp > 1) {
            return "-1";
        }
        
        // DP array to strictly compute the minimum digits required for any combinations of factor 2 and factor 3
        vector<vector<int>> DP(61, vector<int>(41, 1e9));
        DP[0][0] = 0;
        for (int i = 0; i <= 60; ++i) {
            for (int j = 0; j <= 40; ++j) {
                if (i == 0 && j == 0) continue;
                int res = 1e9;
                // Only pull from pre-computed valid states that help progress requirements
                if (i > 0) res = min(res, 1 + DP[max(0, i - 3)][j]);             // digit 8 (provides 2^3)
                if (j > 0) res = min(res, 1 + DP[i][max(0, j - 2)]);             // digit 9 (provides 3^2)
                if (i > 0 || j > 0) res = min(res, 1 + DP[max(0, i - 1)][max(0, j - 1)]); // digit 6 (provides 2^1 * 3^1)
                DP[i][j] = res;
            }
        }

        // Lambda function to retrieve the minimum remaining length heavily needed
        auto req_len = [&](int r2, int r3, int r5, int r7) {
            return r5 + r7 + DP[r2][r3];
        };

        // Arrays to fetch prime factors mappings for digits [0-9] in O(1) time
        int p2[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int p3[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        int p5[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        int p7[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

        int N = num.length();
        int first_zero_idx = num.find('0');
        int first_zero = (first_zero_idx != string::npos) ? first_zero_idx : -1;

        // Array to cache the remaining required prime factors right after sequentially incorporating prefix characters
        vector<array<int, 4>> pref_rem;
        pref_rem.reserve(N + 1);
        pref_rem.push_back({c2, c3, c5, c7});

        for (char c : num) {
            if (c == '0') break;  // Cut caching short effectively diverging
            int d = c - '0';
            auto last = pref_rem.back();
            pref_rem.push_back({
                max(0, last[0] - p2[d]),
                max(0, last[1] - p3[d]),
                max(0, last[2] - p5[d]),
                max(0, last[3] - p7[d])
            });
        }

        // Check if original string already fulfills the condition cleanly
        if (first_zero == -1) {
            auto last = pref_rem.back();
            if (last[0] == 0 && last[1] == 0 && last[2] == 0 && last[3] == 0) {
                return num;
            }
        }

        // To find the smallest string > num, we seek the largest possible diverging point `i`
        int M = (first_zero != -1) ? first_zero : N - 1;
        for (int i = M; i >= 0; --i) {
            int r2 = pref_rem[i][0], r3 = pref_rem[i][1];
            int r5 = pref_rem[i][2], r7 = pref_rem[i][3];

            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                int nr2 = max(0, r2 - p2[d]), nr3 = max(0, r3 - p3[d]);
                int nr5 = max(0, r5 - p5[d]), nr7 = max(0, r7 - p7[d]);

                // Verify if a valid combination of lengths safely satisfies our conditions bounds mapping
                if (req_len(nr2, nr3, nr5, nr7) <= N - 1 - i) {
                    string res = num.substr(0, i);
                    res += (char)('0' + d);
                    
                    int curr2 = nr2, curr3 = nr3, curr5 = nr5, curr7 = nr7;

                    // Greedily fill the rest with the strictly absolute smallest possible digits left-to-right
                    for (int k = i + 1; k < N; ++k) {
                        for (int next_d = 1; next_d <= 9; ++next_d) {
                            int nnr2 = max(0, curr2 - p2[next_d]), nnr3 = max(0, curr3 - p3[next_d]);
                            int nnr5 = max(0, curr5 - p5[next_d]), nnr7 = max(0, curr7 - p7[next_d]);

                            if (req_len(nnr2, nnr3, nnr5, nnr7) <= N - 1 - k) {
                                res += (char)('0' + next_d);
                                curr2 = nnr2; curr3 = nnr3; curr5 = nnr5; curr7 = nnr7;
                                break;
                            }
                        }
                    }
                    return res;
                }
            }
        }

        // If no valid substitution string of identical length `N` surfaced, formulate identically utilizing minimal required extra length 
        int min_length = max(N + 1, req_len(c2, c3, c5, c7));
        string res = "";
        
        int curr2 = c2, curr3 = c3, curr5 = c5, curr7 = c7;
        for (int k = 0; k < min_length; ++k) {
            for (int next_d = 1; next_d <= 9; ++next_d) {
                int nnr2 = max(0, curr2 - p2[next_d]), nnr3 = max(0, curr3 - p3[next_d]);
                int nnr5 = max(0, curr5 - p5[next_d]), nnr7 = max(0, curr7 - p7[next_d]);

                if (req_len(nnr2, nnr3, nnr5, nnr7) <= min_length - 1 - k) {
                    res += (char)('0' + next_d);
                    curr2 = nnr2; curr3 = nnr3; curr5 = nnr5; curr7 = nnr7;
                    break;
                }
            }
        }

        return res;
    }
};