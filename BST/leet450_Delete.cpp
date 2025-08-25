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

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

Node* minVal(Node* root){
        Node* temp = root;
        while(temp->left){
            temp=temp->left;
        }
        return temp;
    }

    Node* maxVal(Node* root){
        Node* temp = root;

        while(temp->right){
            temp = temp->right;
        }
        return temp;
    }

    Node* deleteNode(Node* root, int key) {
        //Base case
        if(root == NULL)return root;

        if(root->data == key){
            // 0 child
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }

            // 1 child
            // left child
            if(root->left && !root->right){
                Node* temp = root->left;
                delete root;
                return temp;
            } 

            // right child
            if(!root->left && root->right){
                Node* temp = root->right;
                delete root;
                return temp;
            }

            // 2 child
            if(root->left && root->right){
                int mini = minVal(root->right)->data;
                root->data = mini;
                root->right = deleteNode(root->right , mini);
                return root;
            }
        }
        else if(root->data > key){
            root->left = deleteNode(root->left , key);
            return root;
        }
        else{
            root->right = deleteNode(root->right , key);
            return root;
        }

        return NULL;
    }

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl<<endl;
    // 10 3 5 6 8 9 11 2 12 6 12 12 -1
    takeInput(root);
    cout<<endl<<endl;

    levelOrderTraversal(root);

    Node* ans = deleteNode(root,4);

    cout<<endl<<endl;

    levelOrderTraversal(ans);
    return 0;
}