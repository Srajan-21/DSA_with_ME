#include <iostream>
#include <stack>
#include<vector>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(int i =  0 ; i < s.length() ; i++){
        char ch = s[i];

        // Opening Brackets
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            // Closing Brackets
            if(!st.empty()){
                char topCh = st.top();
                if(ch == ')' && topCh == '(')
                    st.pop();
                else if(ch == '}' && topCh == '{')
                    st.pop();
                else if(ch == ']' && topCh == '[')
                    st.pop();
                else
                    return false;
            }
            else{
                return false;
            }   
        }
    }
    if(st.empty())
        return true;
    else       
        return false;
    
}

int main(){
    string s = "(({}[]))";

    cout<<isValid(s);
    
    return 0;
}