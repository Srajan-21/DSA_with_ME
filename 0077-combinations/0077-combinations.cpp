class Solution {
public:

    void solve(int start , int n , int k , vector<int>& curr , vector<vector<int>>& result)
    {
        // /Base Case
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }

        for(int i = start ; i <= n ; i++){
            curr.push_back(i);
            solve(i + 1 , n , k , curr , result);
            // BackTrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;

            solve(1 , n , k , curr , result);

        return result;

    }
};