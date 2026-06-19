#include <bits/stdc++.h>
using namespace std;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        // dijkstra's
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        if(n == 1) return 1;

        queue<pair<int,pair<int,int>>> q;

        vector<vector<int>> dist(n, vector<int>(n,1e9));
        dist[0][0] = 1;

        q.push({1,{0,0}});

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int dis = front.first;
            int r = front.second.first;
            int c = front.second.second;

            for(auto i : dirs){
                int nr = r + i.first;
                int nc = c + i.second;

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                    dist[nr][nc] = dis+1;
                    if(nr==n-1 && nc==n-1){
                        return dis+1;
                    }
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        return -1;

        // int n = grid.size();
        // if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;

        // queue<pair<int,int>>q;
        // q.push({0,0});

        // vector<vector<bool>> visited(n, vector<bool>(n,false));
        // vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(n));
        
        // visited[0][0] = true;
        // parent[0][0] = {-1,-1};

        // vector<pair<int,int>> dirs = {{-1,0} , {1,0} , {0,1} , {0,-1} , {1,1} , {1,-1} , {-1,1} , {-1,-1}};

        // while(!q.empty()){
        //     auto [row,col] = q.front();
        //     q.pop();

        //     if(row==n-1 && col==n-1)
        //         break;

        //     for(auto i : dirs){
        //         int nr = row + i.first;
        //         int nc = col + i.second;

        //         if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && !visited[nr][nc])
        //         {
        //             visited[nr][nc] = true;
        //             parent[nr][nc] = {row,col};
        //             q.push({nr,nc});
        //         }
        //     }
        // }

        // if(!visited[n-1][n-1])
        //     return -1;

        // int count = 1;
        // pair<int,int> currNode ={n-1,n-1};

        // while(currNode.first!=0 || currNode.second!=0){
        //     currNode = parent[currNode.first][currNode.second];
        //     count++;
        // }

        // return count;
    }

    int main(){
        vector<vector<int>> grid = {{0,1},{1,0}};
        cout<<shortestPathBinaryMatrix(grid);
    }