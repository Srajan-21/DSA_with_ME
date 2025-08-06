#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(){

    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;

    if(data == -1)
        return NULL;

    Node* root = new Node(data);

    cout<<"Enter data for Left of "<<data<<" Node"<<endl;
    root->left = buildTree();
    
    cout<<"Enter data for right of "<<data<<" Node"<<endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
 
        if(temp == NULL){
            // last level traversed completely
            cout<<endl;
            if(!q.empty()){
                // q still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void solve(Node* root , int sum , int &maxSum , int len , int &maxLen){
    if(root == NULL){
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum , maxSum);
        }
        return;
    }
    sum = sum + root->data;
    
    solve(root->left , sum , maxSum , len+1 , maxLen);
    solve(root->right , sum , maxSum , len+1 , maxLen);
}
int sumOfLongRootToLeafPath(Node* root) {
    int len = 0 , maxLen = 0 , sum = 0 , maxSum = INT_MIN;

    solve(root , sum , maxSum , len , maxLen);
    return maxSum;
}

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1
    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    int maxSum = sumOfLongRootToLeafPath(root);
    cout<<maxSum;

    return 0;
}