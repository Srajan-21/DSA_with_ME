#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> topView(Node* root){
    vector<int> ans;

    if(root == NULL)return ans;

    map<int,int> topNode;

    queue<pair<Node* , int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for hd then do nothing
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left)
            q.push(make_pair(frontNode->left , hd-1));
        if(frontNode->right) 
            q.push(make_pair(frontNode->right , hd+1));
    }

    for(auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    vector<int> ans = topView(root);
    
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}