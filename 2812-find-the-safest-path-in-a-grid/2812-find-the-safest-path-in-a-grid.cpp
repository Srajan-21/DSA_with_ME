class Solution {
public:

    bool canReach(int x , vector<vector<int>> &safeness , int n){
        if(safeness[0][0] < x || safeness[n-1][n-1] < x)return false;

        vector<vector<bool>> visited(n , vector<bool>(n , false));
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0] = true;

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [row , col] = q.front();
            q.pop();

            if(row == n-1 && col == n-1)return true;

            for(auto i : dirs){
                int nr = row + i.first;
                int nc = col + i.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && safeness[nr][nc] >= x){
                    visited[nr][nc] = true;
                    q.push({nr , nc});
                }
            }
        }

        return visited[n-1][n-1];
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> safeness(n , vector<int>(n,-1));
        queue<pair<int,int>> q;

        // make safeness array
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    safeness[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // Run Multiple BFS
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [row , col] = q.front();
            q.pop();
            for(auto i : dirs){
                int nr = row + i.first;
                int nc = col + i.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && safeness[nr][nc] == -1){
                    safeness[nr][nc] = safeness[row][col] + 1;
                    q.push({nr , nc});
                }
            }
        }

        int low = 0;
        int high = 2 * (n-1);
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;
            if(canReach(mid , safeness , n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};