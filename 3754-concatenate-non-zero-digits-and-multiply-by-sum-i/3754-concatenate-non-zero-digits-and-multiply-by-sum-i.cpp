class Solution {
public:
    long long sumAndMultiply(int n) {

        int sum = 0;
        long long rev = 0;

        while(n != 0){
            int a = n % 10;
            if(a != 0){
                sum += a;
                rev = rev * 10 + a;
            }
            n = n /10;
        }

        long long x = 0;
        while(rev != 0){
            x = x*10 + rev%10;
            rev /= 10;
        }

        return x * sum;
        
    }
};