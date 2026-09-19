class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        
        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;  
            
            int left = first[c];
            int right = last[c];
            int i = left;
            while (i <= right) {
                int ch = s[i] - 'a';
                if (first[ch] < left) {
                    left = first[ch];
                    i = left;
                    continue;
                }
                right = max(right, last[ch]);
                i++;
            }
            intervals.push_back({left, right});
        }
        
        set<pair<int,int>> seen(intervals.begin(), intervals.end());
        intervals.assign(seen.begin(), seen.end());
        
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });
        
        vector<string> result;
        int prevRight = -1;
        for (auto& [left, right] : intervals) {
            if (left > prevRight) {
                result.push_back(s.substr(left, right - left + 1));
                prevRight = right;
            }
        }
        
        return result;
    }
};