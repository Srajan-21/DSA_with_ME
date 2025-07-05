#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void middle(stack<int>& st , int &TotalSize) {
    if(st.size() == 0){
        cout<<"No element in Stack";
        return;
    }

    int size1 = (TotalSize%2==0)?(TotalSize/2):(TotalSize/2+1);
    // base case
    if(st.size() == size1){
        cout<<"Middle Element is : " << st.top() << endl;
        return;
    }

    int temp = st.top();
    st.pop();

    // recursive call
    middle(st,TotalSize);

    // backtrack
    st.push(temp);
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
    
    int totalSize = s.size();
    middle(s,totalSize);

    return 0;
}