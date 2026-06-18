#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DisjointSet
{
    vector<int> rank,parent,size;

    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
    public:

    int spanningTree(int V, vector<vector<int>> adj[]){

        vector<pair<int,pair<int,int>>> edges;
        // O(N+E)
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,{node,adjNode}});
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstWT = 0;

        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUParent(u) != ds.findUParent(v)){
                mstWT += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWT;
    }
};

int main() {
    int V = 5;

    vector<vector<int>> adj[5] = {
        {{1,2}, {3,6}},          // 0
        {{0,2}, {2,3}, {3,8}, {4,5}}, // 1
        {{1,3}, {4,7}},          // 2
        {{0,6}, {1,8}},          // 3
        {{1,5}, {2,7}}           // 4
    };

    Solution obj;
    cout << obj.spanningTree(V, adj);

    return 0;
}

// vector<vector<int>> adj[V];

//     // Edge: 0 - 1 (weight 2)
//     adj[0].push_back({1, 2});
//     adj[1].push_back({0, 2});

//     // Edge: 0 - 3 (weight 6)
//     adj[0].push_back({3, 6});
//     adj[3].push_back({0, 6});

//     // Edge: 1 - 2 (weight 3)
//     adj[1].push_back({2, 3});
//     adj[2].push_back({1, 3});

//     // Edge: 1 - 3 (weight 8)
//     adj[1].push_back({3, 8});
//     adj[3].push_back({1, 8});

//     // Edge: 1 - 4 (weight 5)
//     adj[1].push_back({4, 5});
//     adj[4].push_back({1, 5});

//     // Edge: 2 - 4 (weight 7)
//     adj[2].push_back({4, 7});
//     adj[4].push_back({2, 7});