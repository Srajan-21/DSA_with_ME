class Solution {
public:

    bool isValid(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int>res;
        int n = words.size();
        vector<int>prefix(n+1,0);

        for(int i = 0 ; i < n ; i++){
            bool valid = isValid(words[i][0]) && isValid(words[i][words[i].size()-1]);
            prefix[i+1] = prefix[i] + (valid ? 1 : 0);
        }

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            res.push_back(prefix[r+1] - prefix[l]);
        }

        return res;


        // TLE
        // for(int i = 0 ; i < queries.size() ; i++){
        //     int x = queries[i][0];
        //     int y = queries[i][1];
        //     int count = 0;
        //     for(int j = x ; j <= y ; j++){
        //         string s = words[j];

        //         if(isValid(s[0]) && isValid(s[s.length()-1]))
        //             count++;
        //     }
        //     res.push_back(count);
        // }
        // return res;
    }
};