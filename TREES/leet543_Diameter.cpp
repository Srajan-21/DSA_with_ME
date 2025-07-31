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

// TC - O(n)
// SC - O(height)
int height(Node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left , right) + 1;
    return ans;
}

// TC - O(n^2) - bcoz diameter recursively call krne k sat sath har node k height ko bhi recursisvely call kr rhe h
int diameter(Node* root){
    if(root == NULL)return 0;

    int l1 = diameter(root->left);
    int l2 = diameter(root->right);
    int l3 = height(root->right)+height(root->left)+1;

    int ans = max(l1 , max(l2 , l3));
    return ans-1;
}

pair<int , int> diameter_Optimal(Node* root){
    if(root == NULL){
        pair<int , int>p = make_pair(0,0);
        return p;
    }

    pair<int , int> left = diameter_Optimal(root->left);
    pair<int , int> right = diameter_Optimal(root->right);

    int l1 = left.first;
    int l2 = right.first;
    int l3 = left.second + right.second + 1;

    pair<int , int> ans;
    ans.first = max(l1,max(l2,l3));
    ans.second = max(left.second , right.second) + 1;

    return ans;
}

int diam(Node* root){
    return diameter_Optimal(root).first;
}

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"Diameter : "<<diameter(root);
    return 0;
}