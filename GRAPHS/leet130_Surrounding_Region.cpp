#include <bits/stdc++.h>
using namespace std;

    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(board[i][j] == 'O')
                    {
                        board[i][j] = 'S';
                        q.push({i,j});
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

            for(auto i : dirs)
            {
                int nr = r + i.first;
                int nc = c + i.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O')
                {
                    board[nr][nc] = 'S';
                    q.push({nr,nc});
                }
            }
        }

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
int main() {
    
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);

    cout << "Final Board:\n";
    for(auto &row : board)
    {
        for(char ch : row)
            cout << ch << " ";
        cout << "\n";
    }

    return 0;
}