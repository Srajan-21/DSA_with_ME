#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
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

 vector<vector<int>> verticalTraversal(Node* root) {
        map<int , map<int,vector<int>>>nodes;
        queue<pair<Node* , pair<int,int>>>q;
        vector<vector<int>>ans;

        if(root == NULL)return ans;

        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            pair<Node* , pair<int,int>>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if(frontNode->left)
                q.push(make_pair(frontNode->left , make_pair(hd-1,lvl+1)));

            if(frontNode->right)
                q.push(make_pair(frontNode->right , make_pair(hd+1,lvl+1)));
        }
        for(auto i:nodes){
            vector<int>col;
            for(auto j:i.second){
                // sort vector to handle multiple nodes at same hd & level
                sort(j.second.begin(), j.second.end());
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
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

    vector<vector<int>> ans = verticalTraversal(root);
    for(auto lvl:ans){
        for(int val:lvl){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}