class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        const long long MOD = 1e9 + 7;   
        int n = s.size();

        vector<int> pos;
        vector<long long> prefSum;
        vector<long long> prefNum;

        prefSum.push_back(0);
        prefNum.push_back(0);

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0')continue;

            int d = s[i] - '0';
            pos.push_back(i);
            prefSum.push_back(prefSum.back() + d);
            prefNum.push_back((prefNum.back() * 10 + d) % MOD);
        }

        int m = pos.size();

        vector<long long> pow10(m + 1);
        pow10[0] = 1;

        for(int i = 1 ; i <= m ; i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        vector<int> ans;

        for(auto& q : queries){

            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin() , pos.end() , l) - pos.begin();
            int R = upper_bound(pos.begin() , pos.end() , r) - pos.begin() - 1;

            if(L > R){
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];
            int len = R - L + 1;

            long long num = (prefNum[R + 1] - prefNum[L] * pow10[len] % MOD + MOD) % MOD;
            
            ans.push_back(num * sum % MOD);
        }
        return ans;
    }
};