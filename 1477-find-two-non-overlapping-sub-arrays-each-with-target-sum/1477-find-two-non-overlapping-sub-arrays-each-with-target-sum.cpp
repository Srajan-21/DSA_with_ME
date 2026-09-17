class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<long long, int> prefixMap;
        prefixMap[0] = -1;  // prefix_sum -> index
        
        vector<int> best(n, INT_MAX);  // best[i] = min subarray length ending at or before i
        int ans = INT_MAX;
        long long currSum = 0;
        
        for (int i = 0; i < n; i++) {
            currSum += arr[i];
            int currLen = INT_MAX;
            
            if (prefixMap.count(currSum - target)) {
                int j = prefixMap[currSum - target];
                currLen = i - j;  // subarray [j+1 ... i] has sum = target
                
                // Pair with best non-overlapping subarray ending at or before j
                if (j >= 0 && best[j] != INT_MAX) {
                    ans = min(ans, currLen + best[j]);
                }
            }
            
            best[i] = min(i > 0 ? best[i - 1] : INT_MAX, currLen);
            prefixMap[currSum] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};