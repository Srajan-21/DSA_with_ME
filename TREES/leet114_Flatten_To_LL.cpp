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

void flatten(Node* root) {
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left){
                Node* pred = curr->left;
                while(pred->right){
                    pred=pred->right;
                }

                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    flatten(root);

    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;
    
    return 0;
}