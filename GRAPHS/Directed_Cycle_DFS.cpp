#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

bool chkCycleDFS(int node , unordered_map<int,bool> &visited , unordered_map<int,bool> &dfsVisited , unordered_map<int , list<int>> &adj)
{
    visited[node] = 1;
    dfsVisited[node] = 1;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleFound = chkCycleDFS(neighbour , visited , dfsVisited , adj);
            if(cycleFound)
                return true;
        }
        else if(dfsVisited[neighbour])
        {
            return true;
        }
    }

        dfsVisited[node] = 0;
        return false;
}

int cycleDetection(int n, vector<pair<int,int>>&edges)
{
    // create adjacency list
    unordered_map<int , list<int>> adj;
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // to handle disconnected components;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!visited[i])
        {
            bool cycleFound = chkCycleDFS(i , visited , dfsVisited , adj);
            if(cycleFound)
                return true;
        }
    }
    return false;
}

int main(){
    int n = 9;
    int m = 8;

    vector<pair<int,int>> edges = { 
        {1,2},{2,3},{2,4},{4,5},{5,6},{6,4},{3,7},{3,8},{7,8}
    };

    cout<<cycleDetection(n,edges);
}