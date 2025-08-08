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

Node* solve(vector<int>& in , vector<int> &post , int &index , int inorderStart , int inorderEnd , int n , map<int,int>&nodeToIndex){
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    // int element = pre[index--];
    // TreeNode* root = new TreeNode(element);
    // int pos = nodeToIndex[element];

    Node* root = new Node(post[index--]);
    int pos = nodeToIndex[post[index+1]];

    root->right = solve(in , post , index , pos+1 , inorderEnd , n , nodeToIndex);
    root->left = solve(in , post , index , inorderStart , pos-1 , n , nodeToIndex);
    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postOrderIndex = inorder.size()-1;
    map<int,int> nodeToIndex;
    for(int i = 0 ; i < inorder.size() ; i++){
       nodeToIndex[inorder[i]] = i;
    }

    Node* ans = solve(inorder , postorder , postOrderIndex , 0 , inorder.size()-1 , inorder.size() , nodeToIndex);
    return ans;    
}

int main(){
    // Node* root = buildTree();
    // cout<<"Root : "<<root->data<<endl<<endl;
    // // 3 9 -1 -1 20 15 -1 6 -1 -1 7 -1 -1

    vector<int> postOrder = {9,15,7,20,3};
    vector<int> inOrder = {9,3,15,20,7};

    Node* root = buildTree(inOrder , postOrder);

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    return 0;
}