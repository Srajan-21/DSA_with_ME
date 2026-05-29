#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

bool isCycleDFS(int node , int parent , unordered_map<int,bool> &visited , unordered_map<int , list<int>> &adj)
{

     visited[node] = true;
     for(auto neighbour : adj[node])
     {
        if(!visited[neighbour])
        {
        bool cycleDetected = isCycleDFS(neighbour , node , visited , adj);
        if(cycleDetected)return true;
        }
        else if(neighbour != parent)
        {
            // cycle present
            return true;
        }
     }
     return false;
}


string cycleDetection(vector<vector<int>>&edges , int n , int m)
{
    // create adjacency list
    unordered_map<int , list<int>> adj;
    for(int i = 0 ; i < m ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components;
    unordered_map<int,bool> visited;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleDFS(i , -1 , visited , adj);
            if(ans == 1)
             return "YES";
        }
    }
    return "NO";
}

int main(){
    int n = 9;
    int m = 8;

    vector<vector<int>> edges = { 
        {1,2},{2,3},{4,5},{5,6},{5,7},{6,8},{7,8},{8,9}
    };

    cout<<cycleDetection(edges,n,m);
}