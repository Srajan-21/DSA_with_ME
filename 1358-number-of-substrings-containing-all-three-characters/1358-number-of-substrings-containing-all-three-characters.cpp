class Solution {
public:
    int numberOfSubstrings(string s) {

        int ca = 0 , cb = 0 , cc = 0 , j=0 , ans = 0;
        int n = s.length();

        for(int i = 0 ; i < n ; i++){
            while(j < n && (ca == 0 || cb == 0 || cc == 0)){
                if(s[j] == 'a')ca++;
                else if (s[j] == 'b')cb++;
                else if(s[j] == 'c')cc++;
                j++;
            }

            if(ca>=1 && cb>=1 && cc>=1)ans+=n-j+1;

            if(s[i] == 'a')ca--;
            else if (s[i] == 'b')cb--;
            else if(s[i] == 'c')cc--;
        }
        return ans;        
    }
};