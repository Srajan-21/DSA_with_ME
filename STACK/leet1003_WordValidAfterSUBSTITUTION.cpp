#include <iostream>
#include <stack>
using namespace std;

// Using Recursion
bool isValid(string s)
{
    if(s.size()==0) return true;       

    int found = s.find("abc");
    if(found != string::npos){
        // found
        string tleft = s.substr(0,found);
        string tright = s.substr(found+3 , s.size());
        return isValid(tleft+tright);
    }
    return false;
}

// Using Stack
bool isValidStack(string s)
{
    if(s[0]!='a')return false;

    stack<char> st;
    for(char ch:s)
    {
        if(ch=='a')
        st.push(ch);
        else if(ch=='b')
        {
            if(!st.empty() && st.top()=='a')
            {
                st.push('b');
            }
            else return false;
        }
        else{
            // ch=='c'
            if(!st.empty() && st.top()=='b')
            {
                st.pop();
                if(!st.empty() && st.top()=='a')
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else return false;
        }
    }
    return st.empty();
}

int main(){
    string s = "aabcbc";
    if(isValid(s)==1)
    cout<<"true";
    else cout<<"false";
    return 0;
}