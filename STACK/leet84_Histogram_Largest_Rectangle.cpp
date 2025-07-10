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

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    cout<<"Area : "<<getArea(v)<<endl;
    return 0;
}