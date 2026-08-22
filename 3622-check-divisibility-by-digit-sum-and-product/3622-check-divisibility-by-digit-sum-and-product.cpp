class Solution {
public:
    bool checkDivisibility(int n) {

        int t = n;
        int a = 0 , b = 1;

        while(t){
            int x = t%10;
            a += x;
            b *= x;
            t /= 10;
        }

        return n % (a + b) == 0 ? true : false; 
    }
};