#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> visited(V, 0);

    // {weight, node}
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();

        int weight = front.first;
        int node = front.second;

        if (visited[node])
            continue;

        visited[node] = 1;
        sum += weight;

        for (auto &neighbour : adj[node]) {
            int adjNode = neighbour[0];
            int edgeWeight = neighbour[1];

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return sum;
}

int main() {
    int V, E;
    cout<<"Enter : ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // Undirected graph
    }

    
    cout << "Minimum : " << spanningTree(V, adj) << endl;

    return 0;
}