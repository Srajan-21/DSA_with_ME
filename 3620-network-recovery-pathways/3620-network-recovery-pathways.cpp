class Solution {
public:

    vector<int> topologicalSort(vector<vector<int>>& edges , int n)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return ans;
    }

    bool feasible(int mid , int n , vector<int> & topoOrder , vector<bool> & online , vector<vector<pair<int,int>>> &adj , long long k){

        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;

        for(auto i : topoOrder){
            if(dp[i] == LLONG_MAX){
                continue;
            }

            if(i != 0 && online[i] == false){
                continue;
            }

            for(auto j : adj[i]){
                int v = j.first;
                int w = j.second;

                if(v != n-1 && !online[v])
                    continue;

                if(w < mid)
                    continue;

                if(dp[i] + w < dp[v]){
                    dp[v] = dp[i] + w;
                }
            }
        }

        return dp[n-1] <= k;

    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v,w});
        }

        vector<int> topoOrder = topologicalSort(edges , n);

        int minCost = INT_MAX;
        int maxCost = INT_MIN;

        for (auto &e : edges) {
            int cost = e[2];
            minCost = min(minCost, cost);
            maxCost = max(maxCost, cost);
        }

        int best = -1;

        while(minCost <= maxCost){
            int mid = minCost + (maxCost - minCost)/2;

            if(feasible(mid , n , topoOrder , online , adj , k)){
                best = mid;
                minCost = mid + 1;
            }
            else{
                maxCost = mid - 1;
            }
        }

        return best;

    }
};