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

Node* findNode(Node* root, int val){
    if(root == NULL)
        return NULL;
    if(root->data == val)
        return root;

    Node* leftSearch = findNode(root->left, val);
    if(leftSearch)
        return leftSearch;

    return findNode(root->right, val);
}

Node* lca(Node* root , Node* p , Node* q){
    if(root == NULL)
        return NULL;

    if(root->data == p->data)
        return p;

    if(root->data == q->data)
        return q;

    Node* leftAns = lca(root->left , p , q);
    Node* rightAns = lca(root->right , p , q);

    if(!leftAns && !rightAns)
        return NULL;
    else if(leftAns && !rightAns)
        return leftAns;
    else if(!leftAns && rightAns)
        return rightAns;
    else
        return root;
}

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    int val1 = 3, val2 = 7 ;
    Node* p = findNode(root, val1);
    Node* q = findNode(root, val2);
    if(p && q){
        Node* ancestor = lca(root , p , q);
        cout<<"LCA of "<<val1<<" and "<<val2<<" is: "<<ancestor->data<<endl;
    }
    else{
        cout<<"One or both nodes not found in the tree."<<endl;
    }

    return 0;
}