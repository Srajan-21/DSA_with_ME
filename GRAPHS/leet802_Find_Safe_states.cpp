#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int> indegree(n,0);

        for(int i = 0 ; i < n ; i++){
            for(int j : graph[i]){

                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0)q.push(i);
        }

        vector<bool> safe(n,false);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = true;

            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)q.push(neighbour);
            }
        }

        vector<int> result;
        for(int i = 0 ; i < n ; i++){
            if(safe[i])result.push_back(i);
        }

        return result;        
    }
};

int main(){
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    for(int i : ans)cout<<i<<" ";
    cout<<endl;
    return 0;
}