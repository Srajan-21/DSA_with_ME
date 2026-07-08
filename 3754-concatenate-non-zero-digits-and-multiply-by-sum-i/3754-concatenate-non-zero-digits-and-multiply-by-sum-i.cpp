class Solution {
public:
    long long sumAndMultiply(int n) {

        int sum = 0;
        long long x = 0;
        int d = 1;

        while(n != 0){
            int a = n % 10;
            if(a != 0){
                x += d*a;
                d*=10;
                sum+=a;
            }
            n = n /10;
        }

        return x * sum;
        
    }
};