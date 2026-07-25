class Solution {
public:
    int maxProduct(int n) {

        int m1 = 0 , m2 = 0;
        while(n)
        {
            int a = n%10;

            if(a >= m1)
            {
                m2 = m1;
                m1 = a;
            }
            else if(a > m2)
            {
                m2 = a;
            }
             n/=10;
        }

        return m1*m2;

        // vector<int> x;
        // while(n > 0)
        // {
        //     int a = n % 10;
        //     x.push_back(a);
        //     n /= 10;
        // }

        // sort(x.begin() , x.end());
        // int z = x.size();
        // return x[z-1] * x[z-2];
        
    }
};