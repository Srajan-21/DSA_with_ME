class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for(auto ch : s)
        {
            if(ch == '1')
            ones++;
        }

        vector<pair<char , int>> runs;
        for(int i = 0 ; i < n ;)
        {
            int j = i;
            while(j < n && s[j] == s[i])
                j++;

            runs.push_back({s[i] , j - i});
            i = j;
        }

        int ans = ones;
        for(int i = 1 ; i < runs.size() - 1 ; i++)
        {
            if(runs[i].first == '1' && runs[i - 1].first == '0' && runs[i + 1].first == '0')
            {
                ans = max(ans , ones + runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ans;

    }
};