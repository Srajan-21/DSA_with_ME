#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges , int v , int e)
{
    
    unordered_map<int , vector<int>> adj;
    for(auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<int> indegree(v+1,0);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 1 ; i <= v ; i++){
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
            if(indegree[neighbour] == 0)q.push(neighbour);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,4},{3,4},{4,5},{4,6},{5,6}};

    vector<int> ans;
    ans = topologicalSort(edges , 6 , 7);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}