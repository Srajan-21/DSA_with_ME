class Solution {
public:

    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();

        int i = 0 , j = 0;
    
        vector<int> result;
        while( i < m && j < n){

            if(nums1[i] <= nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
            else{
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m){
            result.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            result.push_back(nums2[j]);
            j++;
        }

        return result;

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result = mergeArray(nums1 , nums2);
        int n = result.size();

        if(n % 2 != 0){
            return result[n / 2];
        }
        else{
            return (result[n/2] + result[n/2 - 1]) / 2.0;
        }

    }
};