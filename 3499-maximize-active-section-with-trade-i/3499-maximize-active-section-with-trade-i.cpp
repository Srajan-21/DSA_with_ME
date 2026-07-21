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

        int ans = ones;

        int len1 = 0, len2 = 0, len3 = 0;
        char ch1 = '#', ch2 = '#', ch3 = '#';

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;

            // Current run
            ch1 = ch2;
            len1 = len2;

            ch2 = ch3;
            len2 = len3;

            ch3 = s[i];
            len3 = j - i;

            // Check pattern: 0-run, 1-run, 0-run
            if (ch1 == '0' && ch2 == '1' && ch3 == '0') {
                ans = max(ans, ones + len1 + len3);
            }

            i = j;
        }

        // vector<pair<char , int>> runs;
        // for(int i = 0 ; i < n ;)
        // {
        //     int j = i;
        //     while(j < n && s[j] == s[i])
        //         j++;

        //     runs.push_back({s[i] , j - i});
        //     i = j;
        // }

        // int ans = ones;
        // for(int i = 1 ; i < runs.size() - 1 ; i++)
        // {
        //     if(runs[i].first == '1' && runs[i - 1].first == '0' && runs[i + 1].first == '0')
        //     {
        //         ans = max(ans , ones + runs[i - 1].second + runs[i + 1].second);
        //     }
        // }

        return ans;

    }
};