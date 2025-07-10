#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

vector<int> nextLarge(Node* head){
    vector<int>l;
    while(head){
        l.push_back(head->data);
        head = head->next;
    }

    stack<int>st;
    vector<int>ans(l.size());

    for(int i=0;i<l.size();i++){
        while(!st.empty() && l[i]>l[st.top()]){
            int k=st.top();
            st.pop();
            ans[k]=l[i];
        }
        st.push(i);
    }
 
    return ans;
}

int main(){
    Node* first = new Node(2);
    Node* second = new Node(7);
    Node* third = new Node(4);
    Node* fourth = new Node(3);
    Node* fifth = new Node(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    vector<int> ans = nextLarge(first);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}