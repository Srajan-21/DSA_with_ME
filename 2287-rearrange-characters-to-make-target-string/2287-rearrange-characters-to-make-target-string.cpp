class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        unordered_map<char,int>freq_s;
        unordered_map<char,int>freq_target;

        for(auto ch : s){
            freq_s[ch]++;
        }
        
        for(auto ch : target){
            freq_target[ch]++;
        }

        int ans = INT_MAX;

        for(int i = 0 ; i < target.size() ; i++){
            ans = min(ans , freq_s[target[i]]/freq_target[target[i]]);
        }

        return ans;
        
    }
};