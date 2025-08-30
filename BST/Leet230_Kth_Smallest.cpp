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

int kthSmallest(Node* root , int &i , int k){
    if(!root)
        return -1;

    int left = kthSmallest(root->left , i , k);
    if(left != -1){
        return left;
    }

    i++;
    if(i == k)
        return root->data;

    return kthSmallest(root->right , i ,k);
}

int kthLargest(Node* root , int &i , int k , int n){
    if(!root)
        return -1;

    int left = kthLargest(root->left , i , k , n);
    if(left != -1){
        return left;
    }

    i++;
    if(i == n-k+1)
        return root->data;

    return kthLargest(root->right , i ,k , n);
}


int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl<<endl;
    // 5 4 2 8 6 7 9 -1
    takeInput(root);
    cout<<endl<<endl;

    levelOrderTraversal(root);
    int n = 7;
    int i =0 ;

    cout<<"Kth Smallest : "<<kthSmallest(root , i , 3)<<endl<<endl;

    i=0;
    cout<<"Kth Largest : "<<kthLargest(root , i , 4 , n)<<endl<<endl;


    return 0;
}