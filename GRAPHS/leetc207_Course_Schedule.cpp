#include <vector>
#include <queue>
#include <iostream>
using namespace std;


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto& edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }        

        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0)q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;

            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return count == numCourses;
    }

    int main()
    {
        vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
        int numCourses = 4;
        cout<<canFinish(numCourses,prerequisites);
        return 0;
    }
