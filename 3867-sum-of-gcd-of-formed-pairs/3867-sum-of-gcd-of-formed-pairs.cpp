class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int maxi = INT_MIN;
        vector<int> prefixGCD;

        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
            prefixGCD.push_back(gcd(nums[i] , maxi));
        }

        sort(prefixGCD.begin() , prefixGCD.end());
        long long n = prefixGCD.size();
        long long i = 0;
        long long sum = 0;

        while(i < n / 2){
            sum += gcd(prefixGCD[i] , prefixGCD[n - i - 1]);
            i++;
        }

        return sum;        
    }
};