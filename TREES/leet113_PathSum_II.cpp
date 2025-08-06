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

// MY APPROACH - Not good 
// void solve(TreeNode* root, int targetSum , pair<vector<int>,int> p , vector<vector<int>>&ans){
//     if(root == NULL)
//         return ;

//     p.first.push_back(root->val);
//     p.second+=root->val;

//     if(!root->left && !root->right){
//         if(p.second == targetSum){
//             ans.push_back(p.first);
//         }
//         return ;
//     }
    

//     solve(root->left , targetSum , p , ans);
//     solve(root->right , targetSum , p , ans);

//     p.first.pop_back();
// }
// vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//     vector<int> v;
//     pair<vector<int>, int> p = make_pair(v, 0);
//     vector<vector<int>>ans;
//     solve (root , targetSum , p , ans);
//     return ans;
// }


// Little better but same as mine only not effective mine and this same same
// void solve(TreeNode* root, int targetSum , vector<int>path , int sum, vector<vector<int>>&ans){
//     if(root == NULL)
//         return ;

//     if(!root->left && !root->right){
//         path.push_back(root->val);
//         sum+=root->val;
//         if(sum == targetSum){
//             ans.push_back(path);
//         }
//         return ;
//     }

//     path.push_back(root->val);
//     sum+=root->val;    

//     solve(root->left , targetSum , path , sum , ans);
//     solve(root->right , targetSum , path , sum , ans);
// }

// vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//     vector<int> v;
//     int sum = 0;
//     vector<vector<int>>ans;
//     solve (root , targetSum , v , sum , ans);
//     return ans;
// }

// Best approach by reference passed backtracked least runtimexz
void solve(Node* root, int targetSum , vector<int>&path , int &sum, vector<vector<int>>&ans){
    if(root == NULL)
        return ;

    if(!root->left && !root->right){
        path.push_back(root->data);
        sum+=root->data;
        if(sum == targetSum){
            ans.push_back(path);
        }
        path.pop_back();
        sum-=root->data;
        return ;
    }

    path.push_back(root->data);
    sum+=root->data;    

    solve(root->left , targetSum , path , sum , ans);
    solve(root->right , targetSum , path , sum , ans);

    path.pop_back();
    sum-=root->data;
}
vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<int> v;
    int sum = 0;
    vector<vector<int>>ans;
    solve (root , targetSum , v , sum , ans);
    return ans;
}


int main(){
    Node* root = buildTree();
    cout<<"Root : "<<root->data<<endl<<endl;
    // 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1

    cout<<endl<<endl;
    
    cout<<"Level order : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    int targetSum = 22;
    vector<vector<int>>ans;
    ans = pathSum(root , targetSum);
    for (auto level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}