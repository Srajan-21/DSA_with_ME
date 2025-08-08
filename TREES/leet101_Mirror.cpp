#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val){
        this->val=val;
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
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

bool isMirror(Node* p, Node* q) 
{
    if(p == NULL && q == NULL)
        return true;

    if((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return false;

    bool left = isMirror(p->left , q->right);
    bool right = isMirror(p->right , q->left);

    bool val = p->val == q->val;

    if(left && right && val)return true;
    else return false;
}

bool isSymmetric(Node* root) {
    return isMirror(root->left , root->right);    
}

int main(){
    Node* root = buildTree();
    // 1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1

    cout<<endl<<endl;

    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"Is Mirror? : "<<isSymmetric(root);

    return 0;
}