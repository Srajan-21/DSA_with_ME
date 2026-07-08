class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i : roads){
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }

        vector<bool> visited(n+1 , false);
        int mini = INT_MAX;
        queue<int>q;
        q.push(1);
        visited[1] = true;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto neighbour : adj[node]){
                int neigh = neighbour.first;
                int edgeWt = neighbour.second;

                mini = min(mini , edgeWt);

                if(!visited[neigh]){
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return mini;
    }
};