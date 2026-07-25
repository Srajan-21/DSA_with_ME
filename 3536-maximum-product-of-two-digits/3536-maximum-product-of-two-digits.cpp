class Solution {
public:
    int maxProduct(int n) {

        vector<int> x;
        while(n > 0)
        {
            int a = n % 10;
            x.push_back(a);
            n /= 10;
        }

        sort(x.begin() , x.end());
        int z = x.size();
        return x[z-1] * x[z-2];
        
    }
};