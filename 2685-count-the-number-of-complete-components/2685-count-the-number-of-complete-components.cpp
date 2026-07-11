class DisjointSet{
    vector<int> size , parent;

    public : 
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_Ultimate_Parent(int node){
        if(node == parent[node])
            return node;

        return parent[node] = find_Ultimate_Parent(parent[node]);
    }

    void union_By_Size(int u , int v){

        int ult_u = find_Ultimate_Parent(u);
        int ult_v = find_Ultimate_Parent(v);

        if(ult_u == ult_v)return;

        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        for(auto i : edges){
            ds.union_By_Size(i[0] , i[1]);
        }

        unordered_map<int , int> nodeCount;
        unordered_map<int , int> edgeCount;

        for(int i = 0 ; i < n ; i++){
            int root = ds.find_Ultimate_Parent(i);
            nodeCount[root]++;
        }

        for(auto i : edges){
            int root = ds.find_Ultimate_Parent(i[0]);
            edgeCount[root]++;
        }

        int ans = 0;

        for(auto i : nodeCount){
            int edge = edgeCount[i.first];
            int exp = i.second * (i.second - 1) / 2;

            if(edge == exp)ans++;
        }

        return ans;
    }
};