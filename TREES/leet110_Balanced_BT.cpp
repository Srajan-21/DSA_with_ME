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

// optimal
    pair<bool,int> solve(TreeNode* root){
        if(root == NULL)
        {
            pair<bool , int> p =make_pair(true,0);
            return p;
        }

        pair<int , int> left = solve(root->left);
        pair<int , int> right = solve(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.second = max(left.second , right.second)+1;

        if(leftAns && rightAns && diff)ans.first = true;
        else ans.first = false;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }


    // better but not optimal 
    // int height(TreeNode* root, bool &isbalanced){
    //     if(!root)return 0;

    //     int lh = height(root->left);
    //     int rh = height(root->right);

    //     if(isbalanced && abs(lh-rh)>1)
    //         isbalanced = false;

    //     return max(lh , rh)+1;
    // }
    // bool isBalanced(TreeNode* root){
    //     bool isbalanced = true
    //     height(root , isbalanced);
    //     return isbalanced;
    // }



    // not optimal

    // int height(TreeNode* root) {
    //     if(root == NULL)
    //         return 0;

    //     int left = height(root->left);
    //     int right = height(root->right);

    //     return max(left , right)+1;
    // }

    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL)
    //         return true;

    //     bool left = isBalanced(root->left);
    //     bool right = isBalanced(root->right);

    //     bool diff = abs(height(root->left) - height(root->right)) <= 1;

    //     if(left && right && diff)return true;
    //     else return false;
    // }

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 1 2 3 -1 -1 -1 2 -1 -1
    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"Height : "<<height(root)<<endl;

    cout<<"IS BALANCED:"<<isBalanced(root);

    return 0;
}