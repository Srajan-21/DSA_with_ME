#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <algorithm>
using namespace std;


int reversalCount(string str){
    if(str.size()%2!=0)
        return -1;

    int ans = 0;
    stack<char> s;
    for(int i = 0 ; i<str.length() ;i++){
        char ch = str[i];
        if(ch=='('){
            s.push(ch);
        }else{
            if(!s.empty()&&s.top()=='(')
            {
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    while(!s.empty()){
        char a = s.top();
        s.pop();
        char b = s.top();
        s.pop();
        if(a==b){
            ans+=1;
        }
        else{
            ans +=2; 
        }
    }
    return ans;
}

int main(){
    string s = ")(())(((";
    cout<< reversalCount(s);
   
    return 0;
}
