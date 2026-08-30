class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

    int n = nums.size();
    int minIDX = 0 , maxIdx = 0;

    for(int i = 0 ; i < n ; i++){
        if(nums[i] < nums[minIDX])minIDX = i;
        if(nums[i] > nums[maxIdx])maxIdx = i;
    }    

    int l = min(minIDX , maxIdx);
    int r = max(minIDX , maxIdx);

    int left = r + 1;
    int right = n - l;
    int both = l + 1 + n - r;

    return min({left , right , both});    
    }
};