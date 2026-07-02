class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> healthGrid(m , vector<int>(n,-1));
        healthGrid[0][0] = (grid[0][0] == 1 ? health-1 : health);
        if(healthGrid[0][0] <= 0)return false;

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({healthGrid[0][0] , {0,0}});

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){
            
            auto front = pq.top();
            int h = front.first;
            int r = front.second.first;
            int c = front.second.second;

            pq.pop();

            if(h < healthGrid[r][c])continue;

            for(auto d : dirs){
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newHealth = grid[nr][nc] == 1 ? h-1 : h;

                    if(newHealth > 0 && newHealth > healthGrid[nr][nc]){
                        healthGrid[nr][nc] = newHealth;
                        pq.push({newHealth , {nr , nc}});
                    }
                }
            }
        }

        return healthGrid[m-1][n-1] > 0;
    }
};