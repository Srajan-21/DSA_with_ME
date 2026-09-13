class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int,int>> pts1, pts2;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c]) pts1.push_back({r, c});
                if (img2[r][c]) pts2.push_back({r, c});
            }
        }
        
        if (pts1.empty() || pts2.empty()) return 0;
        
        unordered_map<int, int> count;
        
        for (auto& [r1, c1] : pts1) {
            for (auto& [r2, c2] : pts2) {
                int dr = r2 - r1;
                int dc = c2 - c1;
                int key = (dr + n) * (2 * n) + (dc + n);
                count[key]++;
            }
        }
        
        int result = 0;
        for (auto& [key, cnt] : count) {
            result = max(result, cnt);
        }
        
        return result;
    }
};