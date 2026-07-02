class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int sum = 0;
        for(int i : arr){
            sum += i;
        }
        if(sum%3 != 0)return false;
        int target  = sum/3;
        int count = 0;
        int x = 0;
        for(int i : arr){
            x += i;
            if(x == target){
                count++;
                x = 0;
           }
        }

        return count>=3; //edge case 
    }
};