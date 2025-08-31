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

bool findTarget(Node* root, int k)
{
    vector<int>inorderVal;
    inorder(root , inorderVal);
    int i = 0 , j = inorderVal.size()-1;

    while(i<j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == k)
            return true;
        else if(sum > k)
            j--;
        else
            i++;
    }        
    return false;
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl<<endl;
    // 5 3 2 4 6 7 -1
    takeInput(root);
    cout<<endl<<endl;

    levelOrderTraversal(root);

    cout<<endl<<endl;

    int target=11;
    cout<<findTarget(root,target);
    

    return 0;
}