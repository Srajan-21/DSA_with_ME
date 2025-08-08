#include <iostream>
#include <queue>
#include <vector>
#include <map>

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

Node* solve(vector<int>& in , vector<int> &pre , int &index , int inorderStart , int inorderEnd , int n , map<int,int>&nodeToIndex){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    // int element = pre[index++];
    // TreeNode* root = new TreeNode(element);
    // int pos = nodeToIndex[element];

    Node* root = new Node(pre[index++]);
    int pos = nodeToIndex[pre[index-1]];

    root->left = solve(in , pre , index , inorderStart , pos-1 , n , nodeToIndex);
    root->right = solve(in , pre , index , pos+1 , inorderEnd , n , nodeToIndex);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preOrderIndex = 0;
    map<int,int> nodeToIndex;
    for(int i = 0 ; i < inorder.size() ; i++){
       nodeToIndex[inorder[i]] = i;
    }

    Node* ans = solve(inorder , preorder , preOrderIndex , 0 , inorder.size()-1 , inorder.size() , nodeToIndex);
    return ans;
}

int main(){
    // Node* root = buildTree();
    // cout<<"Root : "<<root->data<<endl<<endl;
    // // 3 9 -1 -1 20 15 -1 6 -1 -1 7 -1 -1

    vector<int> preOrder = {3,9,20,15,7};
    vector<int> inOrder = {9,3,15,20,7};

    Node* root = buildTree(preOrder , inOrder);

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    return 0;
}