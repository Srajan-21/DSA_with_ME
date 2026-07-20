class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        vector<int>temp;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                temp.push_back(grid[i][j]);
            }
        }

        int n = temp.size();
        k = k % n;

        reverse(temp.begin() , temp.end());
        reverse(temp.begin() , temp.begin() + k);
        reverse(temp.begin() + k , temp.end());

        vector<vector<int>> ans;
        vector<int> t;
        int x = grid.size();
        int y = grid[0].size();
        int m = y;
        for(int i = 0 ; i < n ; i++)
        {
           t.push_back(temp[i]); 
            if(t.size() == y){
                ans.push_back(t);
                t.clear();
            }
        }

        return ans;
        
    }
};