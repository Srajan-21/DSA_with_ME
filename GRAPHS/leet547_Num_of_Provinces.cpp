#include<vector>
#include<iostream>
using namespace std;

void DFS(int node , vector<vector<int>>& adj , vector<bool>& visited )
{
    visited[node] = true;
    for(auto i : adj[node])
    {
        if(!visited[i])
            DFS(i,adj,visited);
    }
}
    
int findCircleNum(vector<vector<int>>& isConnected) {

    int n = isConnected.size();
    vector<vector<int>> adj(n);

    for(int i = 0 ; i < n  ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
               adj[j].push_back(i); //because it will traverse through j also so it will automatically make the undirected graph thing in this
            }
        }
    }

    int province = 0;
    vector<bool>visited(n , false);

    for(int i = 0 ; i< n ; i++)
    {
        if(!visited[i])
        {
            province++;
            DFS(i , adj , visited);
        }
    }
    return province;
}

int main()
{
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(isConnected);
    return 0;
}