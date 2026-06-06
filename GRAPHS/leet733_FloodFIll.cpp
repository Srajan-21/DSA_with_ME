#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &image , int r , int c , int oldColor ,  int color)
{
    if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != oldColor)return;

    image[r][c] = color;

    dfs(image,r-1,c,oldColor,color);
    dfs(image,r+1,c,oldColor,color);
    dfs(image,r,c+1,oldColor,color);
    dfs(image,r,c-1,oldColor,color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {    
    int old = image[sr][sc];
    if(old != color)
    {
        dfs(image , sr ,  sc , old , color);
    }
    return image;
}

int main()
{
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1 , sc = 1 , color = 2;

    vector<vector<int>> ans = floodFill(image , sr , sc , color);

    for(int i = 0 ; i < ans.size() ; i++)
    {
        for(int j = 0 ; j < ans[0].size() ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}