#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void solve(stack<int> &st , int target ){
    // base caee
    if(st.empty()){
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    // rec call
    solve(st , target);

    // Backtrack
    st.push(topElement);
}

void insertAtBottom(stack<int> &st){
    if(st.empty()){
        cout<<"Stack is empty , cant insert"<<endl;
        return;
    }

    int target = st.top();
    st.pop();
    solve(st,target);
}

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    
    insertAtBottom(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}