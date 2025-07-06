#include <iostream>
#include <stack>
using namespace std;

int longest(string s){
    stack<int>st;
    st.push(-1);

    int len = 0;
    for(int  i =0 ; i< s.length() ; i++){
        char ch = s[i];
        if(ch == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                int l = i-st.top();
                len = max(len , l);
            }
        }
    }
    return len;
}

int main(){
    string s = ")()())";
    cout<<longest(s);
}