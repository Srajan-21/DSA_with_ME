#include <iostream>
#include<stack>
using namespace std;

void insertSort(stack<int> &s , int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    if(s.top() >= target){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertSort(s,target);

    s.push(topElement);
}

void sortStack(stack<int> &s){
    if(s.empty())return;

    int topElement = s.top();
    s.pop();

    sortStack(s);
    insertSort(s,topElement);
}

int main(){
    stack<int> st;

    st.push(7);
    st.push(11);
    st.push(3);
    st.push(5);
    st.push(9);

    sortStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}