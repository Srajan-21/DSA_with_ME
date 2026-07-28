class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int> freq(26 , 0);
        for(char c : s)
            freq[c - 'a']++;

        string left = "";
        char midd = '\0';

        for(int i = 0 ; i < 26 ; i++)
        {
            int count = freq[i] / 2;
            char ch = 'a' + i;

            for (int j = 0; j < count; j++) {
                left += ch;
            } 

            if(freq[i] % 2)
                midd = char('a' + i);
        }

        string right = left;
        reverse(right.begin() , right.end());

        if(midd != '\0')
            return left + midd + right;
        
        return left + right;







        // O(nlogn)
//         int l = s.length();
//         if(l == 1 || l == 2)return s;

//         string str = s.substr(0 , l / 2);
    
//         sort(str.begin() , str.end());
//         string rev = str;
//         reverse(rev.begin(), rev.end());

//         if(l % 2 == 0)
//             return str + rev;

//         return str + s[l/2] + rev;

    }
};