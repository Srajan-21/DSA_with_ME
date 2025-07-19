#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string decode(string s){
    stack<string> st;
    for(auto ch:s){
        if(ch == ']')
        {
            string sToRepeat = "";
            while(!st.empty() && st.top()!="["){
                string top = st.top();
                sToRepeat += top;
                st.pop();
            }
            st.pop();

            string numTimes = "";
            while(!st.empty() && isdigit(st.top()[0])){
                numTimes += st.top();
                st.pop();
            }

            reverse(numTimes.begin() , numTimes.end());
            int n = stoi(numTimes);

            string currentDecode = "";
            while(n--){
                currentDecode += sToRepeat;
            }
            st.push(currentDecode);
        }
        else {
            string temp(1,ch);
            st.push(temp);
        }
    }

    string ans;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s = "3[a]2[bc]";
    cout<<decode(s);
    return 0;
}