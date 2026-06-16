#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int n, int m, vector<vector<int>>& edges) {
    
    vector<vector<int>> dist(n , vector<int>(n , 1e8));

    for(int i = 0 ; i < n ; i++){
        dist[i][i] = 0;
    }

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        dist[u][v] = wt;
    }

    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(dist[i][k] != 1e8 && dist[k][j] != 1e8 && dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main(){
    int n = 4;
    int m = 5;
    vector<vector<int>> edges = {{0,1,5},{0,3,10},{1,2,3},{2,3,1},{3,0,2}};

    vector<vector<int>> ans = floydWarshall(n , m , edges);
    for(auto &i : ans){
        for(auto &j : i){
            if(j == 1e8)cout<<"INF ";
            else cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
