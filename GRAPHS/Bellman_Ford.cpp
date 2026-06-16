#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V,1e8);
    dist[S] = 0;

    for(int i = 0 ; i < V-1 ; i++){
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
            return {-1};
        }
    }

    return dist;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {{0,1,10},{0,2,5},{1,2,2},{1,3,1},{2,1,3},{2,3,9},{2,4,2},{3,4,4},{4,3,6}};
    int S = 0;

    vector<int> ans = bellmanFord(V , edges , S);
    for(auto i : ans){
        cout<<i<<" ";
    }
    
    return 0;
}
