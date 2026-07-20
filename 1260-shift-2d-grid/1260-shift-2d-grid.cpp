class Solution {
public:

    void reverse(vector<int> &nums,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        vector<int>v;
        for(auto & row : grid)
        {
            for(auto& col : row)
            {
                v.push_back(col);
            }
        }

        int n = v.size();
        k = k % n;

        reverse(v,0,v.size()-k-1);
        reverse(v,v.size()-k,v.size()-1);
        reverse(v,0,v.size()-1);

        int x = grid.size();
        int y = grid[0].size();
        int val = 0;
        for(int i = 0 ; i < x ; i++)
        {
            for(int j = 0 ; j < y ; j++)
            {
                grid[i][j] = v[val++];
            }
        //    t.push_back(temp[i]); 
        //     if(t.size() == y){
        //         ans.push_back(t);
        //         t.clear();
        //     }
        }

        return grid;
        
    }
};