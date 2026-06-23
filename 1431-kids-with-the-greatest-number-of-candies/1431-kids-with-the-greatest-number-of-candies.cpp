class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = INT_MIN;
        for(int i : candies){
            maxi = max(maxi , i);
        }
        vector<bool>res;
        for(int i : candies){
            if(i + extraCandies >= maxi)
                res.push_back(true);
            else
                res.push_back(false); 
        }
        return res;
    }
};