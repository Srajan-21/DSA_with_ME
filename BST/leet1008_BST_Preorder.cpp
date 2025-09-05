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

Node* solve(vector<int> &pre , int mini , int maxi , int &i)
{
    if(i >= pre.size())return NULL;

    if(pre[i] < mini || pre[i] > maxi)return NULL;

    Node* root = new Node(pre[i++]);
    root->left = solve(pre , mini , root->data , i);
    root->right = solve(pre , root->data , maxi , i);
    return root;
}
Node* bstFromPreorder(vector<int>& preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder , mini , maxi , i);        
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};

    Node* root = bstFromPreorder(preorder);

    levelOrderTraversal(root);

    cout<<endl<<endl;
    

    return 0;
}