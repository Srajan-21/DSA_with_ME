class Solution {
public:
    int smallestNumber(int n, int m) {
        
        for(int i = n ; i <= 100 ; i++){
            int a = 1;
            int t = i;
            while(t > 0){
                int x = t % 10;
                a *= x;
                t /= 10;
            }
            if(a % m == 0)
            {
                return i;
                break;
            }
        }
        return 0;
    }
};