class Solution {
public:
    int findGCD(vector<int>& nums) {

        int small = INT_MAX;
        int large = INT_MIN;

        for(auto& i : nums){
            small = min(small , i);
            large = max(large , i);
        }

        return gcd(small , large);
        
    }
};