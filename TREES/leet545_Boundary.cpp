// The LeetCode problem "Boundary of Binary Tree" (Problem Number 545) asks you to find the boundary of a given binary tree. The boundary is defined as the concatenation of:
// The root node.
// The left boundary nodes: These are the nodes along the leftmost path from the root down to the leftmost leaf, excluding the leftmost leaf itself.
// All leaf nodes: These are traversed from left to right.
// The right boundary nodes: These are the nodes along the rightmost path from the root down to the rightmost leaf, traversed in reverse order (from bottom to top), and excluding the rightmost leaf itself.

// Example:
// Consider a binary tree where:
    //     1
    //   2   3
    //  4 5 6 7
// Root = 1
// Left child of 1 = 2
// Right child of 1 = 3
// Left child of 2 = 4 (leaf)
// Right child of 2 = 5 (leaf)
// Left child of 3 = 6 (leaf)
// Right child of 3 = 7 (leaf)
// The boundary traversal would be:
// Root: 1
// Left Boundary (excluding leaf): 2
// Leaves (left to right): 4, 5, 6, 7
// Right Boundary (excluding leaf, reverse order): 3
// Combining these, the final boundary traversal would be [1, 2, 4, 5, 6, 7, 3].


// Constraints:
// The number of nodes in the tree can vary.
// Node values are typically within integer limits.
// Note: Special handling is required for trees with only one node (the root is both the left boundary, right boundary, and a leaf) or trees where one or both subtrees are missing.


#include <iostream>
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

void traverseLeft(Node* root , vector<int>&ans){
    // base case
    if((root == NULL) || (root->left == NULL && root->right == NULL))return;

    ans.push_back(root->data);

    if(root->left)
        traverseLeft(root->left,ans);
    else
        traverseLeft(root->right,ans);
}

void traversaLeaf(Node* root,vector<int>&ans){
    if(root == NULL)return;

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traversaLeaf(root->left , ans);
    traversaLeaf(root->right , ans);
}

void traversaRight(Node* root , vector<int>&ans){
    if((root == NULL) || (root->left ==NULL && root->right == NULL))return;

    if(root->right)
        traversaRight(root->right , ans);
    else
        traversaRight(root->left , ans);

    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int>ans;

    if(root == NULL)return ans;

    ans.push_back(root->data);

    // left part print/store1
    traverseLeft(root->left,ans);
    // left subtree 
    traversaLeaf(root->left,ans);
    // right subtree
    traversaLeaf(root->right,ans);
    // traverse right part
    traversaRight(root->right,ans);
    return ans;
}


int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;

    //         1
    //      2     3  
    //    5    6 7    8
    //  9  10     11

    // 1 2 5 9 -1 -1 10 -1 -1 6 -1 -1 3 7 -1 11 -1 -1 8 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    vector<int> ans = boundary(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    
    return 0;
}