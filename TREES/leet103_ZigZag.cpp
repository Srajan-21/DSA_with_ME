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

vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>>res;
        if(root == NULL)return res;

        queue<Node*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()){
            int size = q.size();

            vector<int>ans(size);

            for(int i = 0;i <size ;i++){
                Node* frontNode = q.front();
                q.pop();

                int index = flag ? i : size - i - 1;
                ans[index] = frontNode->data;

                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);
            }

            flag = !flag;

            res.push_back(ans);
        }
        return res;
    }

int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 7 9 8 10 -1 -1 9 -1 -1 8 -1 -1 7 6 -1 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    vector<vector<int>> ans = zigzagLevelOrder(root);
    for (auto level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}