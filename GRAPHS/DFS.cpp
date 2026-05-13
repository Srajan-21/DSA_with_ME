#include<iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj, vector<int> &component)
{

    // ans store
    component.push_back(node);

    // mark visited
    visited[node] = true;

    // recursive call for all connected node
    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i , visited , adj , component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V , int E , vector<vector<int>> &edges)
{
    // prepare AdjList
    unordered_map<int , list<int>> adj;
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int ,bool>visited;

    //for all nodes all dfs if not visited
    for(int i = 0 ; i < V ; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i , visited , adj , component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main(){
     int vertex , edge;

    cout<<"Enter number of vertices : ";
    cin>>vertex;

    cout<<"Enter number of edges : ";
    cin>>edge;

    vector<vector<int>> edges;

    cout<<"Enter edges : "<<endl;

    for(int i = 0 ; i < edge ; i++)
    {
        int u , v;
        cin >> u >> v;

        edges.push_back({u,v});
    }

    vector<vector<int>>res = depthFirstSearch(vertex , edge , edges);

    cout<<"DSF Traversal : ";
    for(auto component  :res)
    {
        for(auto node : component)
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }

    return 0;
}