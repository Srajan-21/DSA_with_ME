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

int count(Node* root , int &c) {
        if(root == NULL)
            return c;

        c++;
        count(root->left , c);
        count(root->right , c);
        return c;
    }

    int countNodes(Node* root) {
        int c = 0;
        count(root , c);
        return c;
    }

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 3 9 -1 -1 20 15 -1 6 -1 -1 7 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"Nodes : "<<countNodes(root);
    return 0;
}