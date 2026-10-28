class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // dp[i][j] = bitset tracking all achievable XOR values at (i, j)
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0].set(grid[0][0]);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                // Merge reachable XOR values from top and left
                bitset<1024> prev;
                if (i > 0) prev |= dp[i - 1][j];
                if (j > 0) prev |= dp[i][j - 1];
                
                // XOR each reachable value with current cell
                int v = grid[i][j];
                for (int k = 0; k < 1024; k++) {
                    if (prev[k]) {
                        dp[i][j].set(k ^ v);
                    }
                }
            }
        }
        
        // Find the minimum set bit in the destination cell
        for (int k = 0; k < 1024; k++) {
            if (dp[m - 1][n - 1][k]) return k;
        }
        return -1;
    }
};


// class Solution {
// public:
//     // void dfs(vector<vector<int>>& grid , int m , int n , int r , int c , int a , int& mini){
//     //     if(m >= r || n >= c)return;

//     //     a = grid[m][n] ^ a;
        
//     //     if(m == r-1 && n == c-1){
//     //         mini = min(a , mini);
//     //         return;
//     //     }

//     //     dfs(grid , m+1 , n , r , c , a , mini);
//     //     dfs(grid , m , n+1 , r , c , a , mini);

//     // }

   
//     int m, n;
//     vector<vector<vector<int>>> memo;       
//     vector<vector<bool>> computed;

//     vector<int> solve(vector<vector<int>>& grid, int i, int j) {
//         if (computed[i][j]) return memo[i][j];
//         computed[i][j] = true;

//         if (i == m - 1 && j == n - 1) {
//             return memo[i][j] = {grid[i][j]};
//         }

//         unordered_set<int> vals;
//         if (i + 1 < m)
//             for (int v : solve(grid, i + 1, j))
//                 vals.insert(v ^ grid[i][j]);
//         if (j + 1 < n)
//             for (int v : solve(grid, i, j + 1))
//                 vals.insert(v ^ grid[i][j]);

//         memo[i][j] = vector<int>(vals.begin(), vals.end());
//         return memo[i][j];
//     }

//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size(), n = grid[0].size();
//         memo.assign(m, vector<vector<int>>(n));
//         computed.assign(m, vector<bool>(n, false));

//         vector<int> all = solve(grid, 0, 0);
//         return *min_element(all.begin(), all.end());
//     }
// };

//     // int minCost(vector<vector<int>>& grid) {
//     //     int r = grid.size();
//     //     int c = grid[0].size();
//     //     int mini = INT_MAX;
//     //     dfs(grid , 0 , 0 , r , c , 0 , mini);

//     //     return mini;
//     // }
// // };