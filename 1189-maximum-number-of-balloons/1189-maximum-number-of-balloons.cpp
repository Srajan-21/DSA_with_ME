class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int> map;
        for(char& ch : text){
            map[ch]++;
        }

        int cnt_b = map['b']; 
        int cnt_a = map['a']; 
        int cnt_l = map['l']/2; 
        int cnt_o = map['o']/2; 
        int cnt_n = map['n']; 

        int ans = min({cnt_b , cnt_a , cnt_l , cnt_o , cnt_n});
        return ans;
    }
};