#include <iostream>
#include <vector>
using namespace std;

int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};
char dirx[]={'D','L','R','U'};

bool isSafe(int i,int j,int row,int col,vector<vector<int>>& arr,vector<vector<bool>>& visited)
{
    if((i>=0 && i<row) && (j>=0 && j<col) && (arr[i][j]==1)&&(visited[i][j]==false))
    {
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(vector<vector<int>>& arr,int row,int col,int i,int j,vector<vector<bool>> &visited , vector<string>& path,string output)
{
    // base case
    if(i == row-1 && j == col-1)
    {
        // answer found
        path.push_back(output);
        return ;
    }

    for(int k=0;k<4;k++)
    {
        int newx=i+dx[k];
        int newy=j+dy[k];
        char dir=dirx[k];

        if(isSafe(newx,newy,row,col,arr,visited))
        {
            visited[newx][newy]=true;
            solveMaze(arr,row,col,newx,newy,visited,path,output+dir);
            visited[newx][newy]=false;
        }   
    }
}

// void solveMaze(vector<vector<int>> arr,int row,int col,int i,int j,vector<vector<bool>> &visited , vector<string>& path,string output)
// {
//     // base case
//     if(i == row-1 && j == col-1)
//     {
//         // answer found
//         path.push_back(output);
//         return ;
//     }

//     // down -> i+1,j
//     if(isSafe(i+1,j,row,col,arr,visited))
//     {
//         visited[i+1][j] = true;
//         solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
//         // backtrack
//         visited[i+1][j]=false;
//     }
    
//     // left -> i,j-1
//     if(isSafe(i,j-1,row,col,arr,visited))
//     {
//         visited[i][j-1] = true;
//         solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
//         // backtrack
//         visited[i][j-1]=false;
//     }
    
//     // right -> i,j+1
//     if(isSafe(i,j+1,row,col,arr,visited))
//     {
//         visited[i][j+1] = true;
//         solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
//         // backtrack
//         visited[i][j+1]=false;
//     }
    
//     // up -> i-1,j
//     if(isSafe(i-1,j,row,col,arr,visited))
//     {
//         visited[i-1][j] = true;
//         solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
//         // backtrack
//         visited[i-1][j]=false;
//     }
// }

int main(){
    vector<vector<int>> maze {{1,0,0},
                              {1,1,1},
                              {1,1,1}};

    if(maze[0][0]==0)
    {
        cout<<"No path exists"<<endl;
        return 0;
    }

    int row = maze.size();
    int col = maze[0].size();

    vector<vector<bool>>visited(row , vector<bool>(col,false));

    // src ki value k true mark krdete h
    visited[0][0] = true;
    vector <string> path;
    string output = "";

    solveMaze(maze,row,col,0,0,visited,path,output);

    cout<<"printing"<<endl;
    for(auto i:path)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    if(path.size()==0)
    cout<<"no path exists"<<endl;
}