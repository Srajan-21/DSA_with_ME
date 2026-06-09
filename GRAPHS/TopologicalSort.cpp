#include<vector>
#include<stack>
#include<iostream>
using namespace std;

void topoSort(int node , vector<bool> &visited , stack<int>&s , vector<vector<int>> &adj){
    visited[node] = 1;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour , visited , s , adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges , int v , int e)
{
    vector<vector<int>> adj(v+1);
    for(auto &edge : edges)
    {   
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v,0);
    stack<int>s;
    for(int i = 1 ; i <= v ; i++){
        if(!visited[i])
            topoSort(i , visited , s , adj);
    }

    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
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