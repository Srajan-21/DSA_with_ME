class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<int,int>freq;
        int maxi = 0;
        for(int n : nums){
            freq[n]++;
            maxi = max(n,maxi);
        }

        int ans = 1;

        if(freq.count(1)){
            if (freq[1] % 2 == 0)
                ans = freq[1] - 1;
            else
                ans = freq[1];
        }

        for(auto [num , fr] : freq){

            if(num == 1)continue;
            
            long long x = num;
            int len = 0;

            while(x <= maxi && freq[x] >= 2){
                len+=2;
                x = x*x;
            }

            if (x <= maxi && freq[x] >= 1)len++;
            else len--;

            ans = max(ans,len);
        }

        return ans;
    }
};