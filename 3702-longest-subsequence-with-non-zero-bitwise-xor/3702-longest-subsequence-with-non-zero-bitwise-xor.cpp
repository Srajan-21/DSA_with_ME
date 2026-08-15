class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0 , a = 0;
        for(int i : nums){
            x ^= i;
            if(i == 0)
                a++;
        }

        if(x != 0)return nums.size();
        if(a == nums.size())return 0;
        return nums.size() - 1;
    }
};