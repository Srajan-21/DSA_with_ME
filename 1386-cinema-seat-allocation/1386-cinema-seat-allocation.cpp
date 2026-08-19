class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        vector<vector<int>> avail = {
            {2, 3, 4, 5},
            {4, 5, 6, 7},
            {6, 7, 8, 9}
        };

        // row -> reserved seats
        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, reserved] : mp) {
            
            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat : avail[0]) {
                if (reserved.count(seat))
                    left = false;
            }

            for (int seat : avail[1]) {
                if (reserved.count(seat))
                    middle = false;
            }

            for (int seat : avail[2]) {
                if (reserved.count(seat))
                    right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};