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

bool isSameTree(Node* p, Node* q) 
{
    if(p == NULL && q == NULL)
        return true;

    if((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return false;

    bool left = isSameTree(p->left , q->left);
    bool right = isSameTree(p->right , q->right);

    bool val = p->val == q->val;

    if(left && right && val)return true;
    else return false;
}

int main(){
    Node* root1 = buildTree();

    cout<<endl<<endl;

    Node* root2 = buildTree();

    cout<<endl<<endl;

    cout<<"Root1 : "<<root1->val<<endl<<endl;
    // 3 9 -1 -1 20 15 -1 6 -1 -1 7 -1 -1
    cout<<"Root2 : "<<root2->val<<endl<<endl;

    cout<<endl<<endl;
    
    cout<<"Level order 1: "<<endl;
    levelOrderTraversal(root1);
    
    cout<<endl<<endl;
    
    cout<<"Level order 1: "<<endl;
    levelOrderTraversal(root2);
    cout<<endl<<endl;

    cout<<"Is Same or Identical : "<<isSameTree(root1 , root2);


    return 0;
}