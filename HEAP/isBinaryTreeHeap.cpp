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


int countNodes(Node* root)
{
    if(root == NULL)return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root , int index , int cnt)
{
    if(root == NULL)return true;

    if(index >= cnt)
        return false;
    else
    {
        bool left = isCBT(root->left , 2*index + 1 , cnt);
        bool right = isCBT(root->right , 2*index + 2 , cnt);
        return (left && right);
    }
}

bool isMaxOrder(Node* root)
{
    if(root->left == NULL && root->right == NULL)return true;

    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

bool isHeap(Node* root)
{
    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root , index , totalCount) && isMaxOrder(root))
        return true;
    else
        return false;
}



int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 20 10 5 -1 -1 15 -1 -1 -1 35 30 -1 -1 42 -1 -1

    cout<<"level order : "<<endl;
    levelOrderTraversal(root);
    
    cout<<isHeap(root);
    return 0;
}