#include <bits/stdc++.h>
using namespace std;

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i, j});
                        grid[i][j] = -1;
                    }
                }
            }
        }

        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto d : dirs)
            {
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = -1;
                    q.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }

int main() {
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << numEnclaves(grid) << endl;

    return 0;
}