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

void inorder(Node* root , vector<int>& in)
{
    if(root == NULL)return ;

    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

Node* flatten(Node* root)
{
    vector<int>inorderVal;
    inorder(root , inorderVal);
    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    for(int i = 1 ; i < n ; i++)
    {
        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl<<endl;
    // 5 3 2 4 6 7 -1

    //       4
    //   2       6
    // 1   3   5   7
    takeInput(root);
    cout<<endl<<endl;

    levelOrderTraversal(root);

    cout<<endl<<endl;

    Node* head = flatten(root);

    print(head);

    return 0;
}