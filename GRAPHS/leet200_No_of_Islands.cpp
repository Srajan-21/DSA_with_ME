#include <vector>
#include <queue>
#include <iostream>
using namespace std;

    int numIslands(vector<vector<char>>& grid) {
        
        int island = 0;
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    q.push({i,j});
                    visited[i][j]=true;

                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(auto d : dirs){
                            int nr = r+d.first;
                            int nc = c+d.second;

                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && !visited[nr][nc]){
                                visited[nr][nc] = 1;
                                q.push({nr,nc});
                            }                 
                        }
                    }
                    island++;
                }
            }
        }
        return island;
    }

int main()
{
    vector<vector<char>> grid = {
                                {'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};
    cout<<numIslands(grid);
    return 0;
}