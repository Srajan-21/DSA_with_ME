#include <vector>
using namespace std;
#include<queue>
#include<iostream>

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        queue<pair<int,int>> q;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
                else
                    ans[i][j] = -1;
            }
        }



        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            
            pair<int,int> node = q.front();
            int distance = ans[node.first][node.second];
            q.pop();

            for(auto i : dirs)
            {
                int nr = node.first + i.first;
                int nc = node.second + i.second;

                if(nr >= 0 && nr < n && nc < m && nc >= 0 && ans[nr][nc] == -1)
                {
                    ans[nr][nc] = distance+1;
                    q.push({nr,nc});
                }
            }            
        }
    return ans;
    }

    int main()
    {
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};

        vector<vector<int>> ans = updateMatrix(mat);

        for(int i = 0 ; i < ans.size() ; i++)
        {
            for(int j = 0 ; j < ans[0].size() ; j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }