class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> st(nums.begin() , nums.end());
        int m = k;

        while(st.count(m))
        {
            m += k;
        }

        return m;

    }
};