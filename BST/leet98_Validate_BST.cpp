#include <iostream>
#include <queue>
#include <limits.h>
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

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

bool isValidateBST(Node* root , long long min , long long max){
    if(root == NULL)
        return true;

    if(root->data >= min && root->data <= max)
    {
        bool left = isValidateBST(root->left , min , root->data);
        bool right = isValidateBST(root->right , root->data , max);
        return left && right;
    }
    else
        return false;
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl<<endl;
    // 10 3 5 6 8 9 11 2 12 6 12 12 -1
    takeInput(root);
    cout<<endl<<endl;

    levelOrderTraversal(root);

    cout<<"Is Valid or Not : "<<isValidateBST(root , LLONG_MIN , LLONG_MAX);

    return 0;
}