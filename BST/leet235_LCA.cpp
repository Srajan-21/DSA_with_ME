#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
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

Node* insertIntoBST(Node* root , int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        // right side insert
        root->right = insertIntoBST(root->right , d);
    }
    else{
        // left side insert
        root->left = insertIntoBST(root->left , d);
    }

    return root;
}

Node* lca(Node* root , Node* p , Node* q){
    // SC-O(1)
        while(root != NULL){
            if(root->data < p->data && root->data < q->data) root = root->right;
            else if(root->data > p->data && root->data > q->data)root=root->left;
            else return root;
        }
        return NULL;

        // TC-O(h) SC-O(h)
        // if(root == NULL)return NULL;

        // if(root->val < p->val && root->val < q->val)
        //     return lowestCommonAncestor(root->right , p , q);
        
        // if(root->val > p->val && root->val > q->val)
        //     return lowestCommonAncestor(root->left , p , q);

        // return root;
}



void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl<<endl;
    // 6 2 8 0 4 7 9 3 4 5 -1
    takeInput(root);
    cout<<endl<<endl;

    Node* p=new Node(3);
    Node* q = new Node(8);

    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Lowest common Ancestor of "<<p->data<<" & "<<q->data<<" : "<<lca(root,p,q)->data;


    return 0;
}