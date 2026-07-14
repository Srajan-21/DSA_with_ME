class Solution {
public:

    void solve(vector<int>& candidates , int start , int target , vector<int> &curr , vector<vector<int>>& result){

        if(target == 0){
            result.push_back(curr);
            return;
        }

        if(target < 0)return;

        for(int i = start ; i < candidates.size() ; i++){
            curr.push_back(candidates[i]);
            solve(candidates , i , target-candidates[i] , curr , result);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>curr;
        vector<vector<int>> result;
        solve(candidates , 0 , target , curr ,result);

        return result;


    }
};