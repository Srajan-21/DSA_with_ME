class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        vector<int>temp;
        for(auto & row : grid)
        {
            for(auto& col : row)
            {
                temp.push_back(col);
            }
        }

        int n = temp.size();
        k = k % n;

        reverse(temp.begin() , temp.end());
        reverse(temp.begin() , temp.begin() + k);
        reverse(temp.begin() + k , temp.end());

        int x = grid.size();
        int y = grid[0].size();
        int val = 0;
        for(int i = 0 ; i < x ; i++)
        {
            for(int j = 0 ; j < y ; j++)
            {
                grid[i][j] = temp[val++];
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