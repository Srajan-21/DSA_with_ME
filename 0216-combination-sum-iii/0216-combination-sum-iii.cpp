class Solution {
public:

    void solve(int start , int k , int n , vector<int>& curr , vector<vector<int>>& result){
        if(curr.size() == k){
            if(n == 0)
                result.push_back(curr);
            return;
        }

        if(n < 0){
            return;
        }

        for(int i = start + 1 ; i <= 9 ; i++){
            curr.push_back(i);
            solve(i , k , n - i , curr , result);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;

        solve(0 , k , n , curr , result);

        return result;
    }
};