class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n =arr.size();
        sort(arr.begin() , arr.end());
        if(arr[0] != 1)arr[0] = 1;


        for(int i = 1 ; i < n ; i++){
            if(abs(arr[i]-arr[i-1]) > 1)
                arr[i] = min(arr[i-1] + 1 , arr[i]);        
        }

        return arr[n-1];
   
        
        
        
        
        
        
        
        
        
        
        
        
        // sort(arr.begin(), arr.end());

        // arr[0] = 1;

        // for (int i = 1; i < arr.size(); i++) {
        //     arr[i] = min(arr[i], arr[i - 1] + 1);
        // }

        // return arr.back();
    }
};