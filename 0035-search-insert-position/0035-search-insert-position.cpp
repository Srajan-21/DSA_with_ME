class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() , l = 0 , h = n-1;

        while(l <= h){
            int mid = l + (h-l)/2;
            if(target > nums[mid])l = mid+1;
            else if(target < nums[mid])h = mid - 1;
            else return mid;
        }
        return l;
    }
};