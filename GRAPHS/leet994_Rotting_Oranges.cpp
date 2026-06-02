#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {

    queue<pair<int,int>> q;
    int fresh_count = 0;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2)
                q.push({i, j});
            else if(grid[i][j] == 1)
                fresh_count++;
        }
    }

    if(fresh_count == 0)
        return 0;

    int minutes = 0;
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    while(!q.empty()) {
        int size = q.size();
        bool rot = false;

        for(int i = 0; i < size; i++) {
            pair<int,int> node = q.front();
            q.pop();

            for(auto d : dirs) {
                int nr = node.first + d.first;
                int nc = node.second + d.second;

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh_count--;
                    rot = true;
                }
            }
        }

        if(rot)
            minutes++;
    }

    return (fresh_count == 0) ? minutes : -1;
}

int main() {

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << orangesRotting(grid) << endl;

    return 0;
}