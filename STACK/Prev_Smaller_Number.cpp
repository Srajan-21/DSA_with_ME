#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmall(vector<int> arr){
    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());

    for(int i=0;i<arr.size();i++){
        int curr = arr[i];
        while(s.top()>=curr){
            s.pop();
        }

        ans[i]=s.top();
        s.push(curr);
    }

    return ans;
}

int main(){
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    for(int i = 0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    vector <int> ans = prevSmall(input);
    for(int i = 0;i<input.size();i++){
        cout<<ans[i]<<" ";
    }
}