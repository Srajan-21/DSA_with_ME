#include <bits/stdc++.h>
using namespace std;


    // bool topoDFS(int node , vector<int> &visited , stack<int>& s , vector<vector<int>>&adj){
    //     visited[node] = 1;
    //     for(auto & neighbour : adj[node]){
    //         if(visited[neighbour] == 0){
    //             if(!topoDFS(neighbour , visited , s , adj))return false;
    //         }
    //         else if(visited[neighbour] == 1)return false;
    //     }
    //     visited[node] = 2;
    //     s.push(node);
    //     return true;
    // }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Using DFS
        // vector<vector<int>> adj(numCourses);
        // for(auto &edge : prerequisites){
        //     int u = edge[0];
        //     int v = edge[1];
        //     adj[v].push_back(u);
        // }

        // vector<int>visited(numCourses);
        // stack<int> s;
        
        // for(int i = 0 ; i < numCourses ; i++){
        //     if(visited[i]==0)
        //         if(!topoDFS(i , visited , s , adj))return {};
        // }

        // vector<int> ans;
        // while(!s.empty()){
        //     ans.push_back(s.top());
        //     s.pop();
        // }

        // return ans;


        // Kahn's Algorithm
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto &i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0)q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            ans.push_back(i);

            for(auto & neighbours : adj[i]){
                indegree[neighbours]--;

                if(indegree[neighbours] == 0)q.push(neighbours);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};
    }

    int main()
    {
        vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
        int numCourses = 4;
        vector<int> ans = findOrder(numCourses,prerequisites);
        for(auto &i : ans)cout<<i<<" ";
        return 0;
    }