#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <algorithm>
using namespace std;


string remove(string str){
    stack <char> s;
    for(int i = 0 ; i<str.length() ;i++){
        if(!s.empty() && s.top() == str[i]){
            s.pop();
        }
        else{
            s.push(str[i]);
        }
    }

    string ans;
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s = "abbaca";
    string ans = remove(s);
    for(int i = 0 ; i<ans.length() ;i++){
        cout<<ans[i]<<" ";
    }  
    return 0;
}
