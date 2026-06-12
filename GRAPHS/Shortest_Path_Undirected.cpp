#include <iostream>
#include <vector>
#include<unordered_map>
#include <list>
#include<queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>>& edges , int n , int m , int s , int t){
    
    unordered_map<int , list<int>>adj;
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS
    unordered_map<int , bool> visited;
    unordered_map<int , int>parent;
    queue<int>q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    int n = 8;      
    int m = 9;      

    vector<pair<int,int>> edges = {
        {0,1},
        {0,3},
        {1,2},
        {3,4},
        {4,5},
        {5,6},
        {6,7},
        {2,7},
        {1,4}
    };

    int source = 0;
    int target = 7;

    vector<int> path = shortestPath(edges, n, m, source, target);

    cout << "Shortest Path: ";

    for(int node : path){
        cout << node << " ";
    }

    cout << endl;

    return 0;
}