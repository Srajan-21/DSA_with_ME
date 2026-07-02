class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> result;
        for(int num : nums){
            for(char ch : to_string(num)){
                result.push_back(ch-'0');
            }
        }
        return result;
        
        // int size = nums.size();
        // vector<int>result;
        // for(int num : nums){
        //     vector<int> temp;
        //     while(num != 0){
        //         int b = num % 10;
        //         num = num / 10;
        //         temp.push_back(b);
        //     }
        //     for(int i = temp.size()-1 ; i >= 0 ; i--)
        //         result.push_back(temp[i]);
        // }

        return result;
    }
};