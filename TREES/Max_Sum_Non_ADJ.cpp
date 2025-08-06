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

pair<int,int> solve(Node* root){
    if(root == NULL){
        pair<int,int> p =make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first , left.second) + max(right.first , right.second);
    return res;
}

int getMaxSum(Node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first ,ans.second);
}

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 1 2 4 8 -1 -1 -1 5 -1 -1 3 6 -1 9 -1 -1 7 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Max Sum is : "<<getMaxSum(root);

    return 0;
}