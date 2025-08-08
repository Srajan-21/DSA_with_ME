#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

// create mapping
// return target node
void createParentMapping(Node* root , int &target , map<Node* , Node*>&nodeToParent , Node* &res){
   
    queue<Node*>q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->data == target)
        {
            res = front;
        }

        if(front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
}

// TC - O(N)
// SC - O(N)
int amountOfTime(Node* root, int start) {
    Node *res = NULL;
    map<Node* , Node*> nodeToParent;
    createParentMapping(root , start , nodeToParent , res);
    
    map<Node* , bool>visited;

    queue<Node*>q;

    q.push(res);
    visited[res] = true;

    int ans = 0;

    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left]=1;
            }

            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right]=1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1)
            ans++;
    }
    return ans;
}

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 1 5 -1 4 9 -1 -1 2 -1 -1 3 10 -1 -1 6 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"Enter start node : ";
    int start;
    cin>>start;
    int time = amountOfTime(root , start);

    cout<<endl<<endl;
    cout<<"Time taken : "<<time;
    
    return 0;
}