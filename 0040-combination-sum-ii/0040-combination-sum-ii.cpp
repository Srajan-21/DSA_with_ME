class Solution {
public:

    void solve(int start , vector<int>& candidates, int target , vector<int>& curr , vector<vector<int>>& result){

        if(target == 0){
            result.push_back(curr);
            return;
        }

        if(target < 0)return;

        for(int i = start ; i < candidates.size() ; i++){

            if(i > start && candidates[i] == candidates[i - 1])
               continue;

            if(candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            solve(i + 1 , candidates , target - candidates[i] , curr , result);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin() , candidates.end());
        vector<int>curr;
        vector<vector<int>>result;

        solve(0 , candidates , target , curr , result);

        return result;
    }
};