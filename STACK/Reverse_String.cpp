#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    stack<char> st;

    for(int i = 0 ; i < s.size() ; i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    vector<char> str = {'S', 'r', 'a', 'j', 'a', 'n'};
    reverseString(str);

    

    return 0;

}