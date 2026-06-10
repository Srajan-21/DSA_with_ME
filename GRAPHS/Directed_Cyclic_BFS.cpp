#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;

bool detectCycleInDirectedGraph(int n , vector<pair<int,int>>& edges)
{
    
    unordered_map<int , vector<int>> adj;
    for(auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    vector<int> indegree(n+1,0);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 1 ; i <= n ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // BFS
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;

        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)q.push(neighbour);
        }
    }
    
    if(count == n)return false;
    else return true;
}

int main(){
    vector<pair<int,int>> edges = {{1,2},{2,3},{3,4},{4,1}};

    vector<int> ans;
    cout<< detectCycleInDirectedGraph(4 , edges);
    
    return 0;
}