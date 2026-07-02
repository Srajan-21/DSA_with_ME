class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n =arr.size();
        sort(arr.begin() , arr.end());
        if(arr[0] != 1)arr[0] = 1;


        for(int i = 1 ; i < n ; i++){
            if(abs(arr[i]-arr[i-1]) <= 1)continue;
            else{
                arr[i] = arr[i-1] + 1;
            }            
        }

        // for(int i = 1 ; i < n ; i++){
        //     if(abs(arr[i]-arr[i-1]) > 1)
        //         arr[i] = min(arr[i-1] + 1 , arr[i]);        
        // }

        return arr[n-1];
    }
};