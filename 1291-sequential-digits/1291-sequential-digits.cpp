class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        string s = "123456789";
        vector<int> result;

        for(int L = 2 ; L < 10 ; L++){
            for(int i = 0 ; i <= s.length() - L ; i++){
                int digit = stoi(s.substr(i , L));
                if(digit >= low && digit <= high){
                    result.push_back(digit);
                }
            }
        }

        return result;

    }
};