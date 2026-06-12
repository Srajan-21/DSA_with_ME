#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <list>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {

    unordered_map<int, list<pair<int,int>>> adj;

    // Create adjacency list
    for(int i = 0; i < edges; i++) {

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // Undirected graph
    }

    vector<int> dist(vertices, INT_MAX);

    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while(!st.empty()) {

        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour : adj[topNode]) {

            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if(nodeDist + weight < dist[nextNode]) {

                auto record = st.find({dist[nextNode], nextNode});

                if(record != st.end())
                    st.erase(record);

                dist[nextNode] = nodeDist + weight;

                st.insert({dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

int main() {

    int vertices = 5;
    int edges = 6;

    vector<vector<int>> vec = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,4,3},
        {3,4,1}
    };

    int source = 0;

    vector<int> ans = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";

    for(int i = 0; i < vertices; i++) {
        cout << "Node " << i << " -> ";
        if(ans[i] == INT_MAX)
            cout << "INF";
        else
            cout << ans[i];
        cout << endl;
    }

    return 0;
}