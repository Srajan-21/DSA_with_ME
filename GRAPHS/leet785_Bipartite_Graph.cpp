#include <bits/stdc++.h>
using namespace std;

    bool DFS(int node , int clr , vector<int> &color , vector<vector<int>>& graph){
        bool val = true;
        for (int neighbour : graph[node])
        {
            if(color[neighbour] == -1)
            {
                color[neighbour] = abs(1-clr);
                val = DFS(neighbour , abs(1-clr) , color , graph);
                if(!val)return false;
            }
            else if(color[neighbour] != -1)
            {
                if(color[neighbour] == clr)return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

    int n = graph.size();
    vector<int>color(n,-1);
    bool ans = true;

    for(int i = 0 ; i < graph.size() ; i++)
    {
        if(color[i] == -1){
            color[i] = 0;
            ans = DFS(i,color[i],color,graph);
            if(!ans)return false;
        }
    }   
    return ans;
    }

    int main()
    {
        vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
        cout<<isBipartite(graph);
        return 0;
    }
