#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<int> nextSmall(vector<int>&input){
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    for(int i = input.size()-1 ; i>=0;i--){
        int curr = input[i];

        while(s.top()!=-1 && input[s.top()]>=curr){
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmall(vector<int>&input){
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());


    for(int i = 0 ; i<input.size();i++){
        int curr = input[i];

        while(s.top()!=-1 && input[s.top()]>=curr){
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int getArea(vector<int> &height){
    vector<int> prev = prevSmall(height);
    vector<int> next = nextSmall(height);
    
    int maxArea = INT_MIN;
    int size = height.size();
    for(int i=0;i<height.size();i++){
        int len = height[i];

        if(next[i] == -1){
            next[i] = size;
        }

        int wid = next[i]-prev[i]-1;
        int area = len * wid;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int maxRectangle(vector<vector<char> >& matrix){
    vector<vector<int> >v;
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0 ; i < n ; i++){
        vector<int> t;
        for(int j= 0;j<m;j++)
        {
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }

    int area = getArea(v[0]);
    for(int i = 1;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]){
                v[i][j]+=v[i-1][j];
            }
            else{
                v[i][j]=0;
            }
        }
        area = max(area,getArea(v[i]));
    }
    return area;
}

int main(){
    vector<vector<char> > matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};

    cout<<"Area : "<<maxRectangle(matrix)<<endl;
    return 0;
}