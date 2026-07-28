class Solution {
public:
    string smallestPalindrome(string s) {
        
        int l = s.length();
        if(l == 1 || l == 2)return s;

        string str = s.substr(0 , l / 2);
    
        sort(str.begin() , str.end());
        string rev = str;
        reverse(rev.begin(), rev.end());

        if(l % 2 == 0)
            return str + rev;

        return str + s[l/2] + rev;

    }
};