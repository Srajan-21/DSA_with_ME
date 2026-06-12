#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
#include <climits>

using namespace std;

// Adjacency list: node -> (neighbour, weight)
unordered_map<int, list<pair<int,int>>> adj;

// DFS for Topological Sort
void dfs(int node, unordered_map<int,bool> &vis, stack<int> &topo) {

    vis[node] = true;

    for(auto neighbour : adj[node]) {
        if(!vis[neighbour.first]) {
            dfs(neighbour.first, vis, topo);
        }
    }

    topo.push(node);
}

// Shortest Path using Topological Sort
void getShortestPath(int src, int n) {

    unordered_map<int,bool> visited;
    stack<int> topo;

    // Topological Ordering
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            dfs(i, visited, topo);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while(!topo.empty()) {

        int top = topo.top();
        topo.pop();

        if(dist[top] != INT_MAX) {

            for(auto neighbour : adj[top]) {

                int v = neighbour.first;
                int wt = neighbour.second;

                if(dist[top] + wt < dist[v]) {
                    dist[v] = dist[top] + wt;
                }
            }
        }
    }

    cout << "Shortest Distance from Source " << src << ":\n";

    for(int i=0;i<n;i++) {
        if(dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    cout << endl;
}

int main() {

    int n = 6;

    // DAG Edges (u, v, weight)

    adj[0].push_back({1,5});
    adj[0].push_back({2,3});

    adj[1].push_back({2,2});
    adj[1].push_back({3,6});

    adj[2].push_back({3,7});
    adj[2].push_back({4,4});
    adj[2].push_back({5,2});

    adj[3].push_back({4,-1});

    adj[4].push_back({5,-2});

    int src = 1;

    getShortestPath(src, n);

    return 0;
}