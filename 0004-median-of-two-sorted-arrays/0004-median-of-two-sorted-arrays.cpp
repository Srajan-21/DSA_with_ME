class Solution {
public:

    // TC - O(m + n)
    // SC - O(m + n)
    // vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2){
    //     int m = nums1.size();
    //     int n = nums2.size();

    //     int i = 0 , j = 0;
    
    //     vector<int> result;
    //     while( i < m && j < n){

    //         if(nums1[i] <= nums2[j]){
    //             result.push_back(nums1[i]);
    //             i++;
    //         }
    //         else{
    //             result.push_back(nums2[j]);
    //             j++;
    //         }
    //     }

    //     while(i < m){
    //         result.push_back(nums1[i]);
    //         i++;
    //     }

    //     while(j < n){
    //         result.push_back(nums2[j]);
    //         j++;
    //     }

    //     return result;

    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        // Always perform BS on smaller array
        if(m > n)
            return findMedianSortedArrays(nums2 , nums1);

        // Total num of elements that should be on the left side
        int leftSize = (m + n + 1) / 2;

        int low = 0 , high = m;

        while(low <= high){

            // partition in nums1
            int cut1 = low + (high - low) / 2;

            // corresponding partition in nums2
            int cut2 = leftSize - cut1;

            // Left and Right elements arount cut1
            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int R1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            // Left and Right elements arount cut1
            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int R2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if(L1 <= R2 && L2 <= R1){
                // Odd total elements
                if((m + n) % 2 == 1)
                    return max(L1 , L2);

                // Even total elements
                return (max(L1 , L2) + min(R1 , R2)) / 2.0;
            }

            // We have taken too many elements from nums1
            else if(L1 > R2){
                high = cut1 - 1;
            }

            // We need tot take make elements from nums1
            else{
                low = cut1 + 1;
            }
        }

        return 0.0;


        
        // vector<int> result = mergeArray(nums1 , nums2);
        // int n = result.size();

        // if(n % 2 != 0){
        //     return result[n / 2];
        // }
        // else{
        //     return (result[n/2] + result[n/2 - 1]) / 2.0;
        // }

    }
};