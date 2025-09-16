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

    if(d >= root->data){
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







// Approach 1 TC , SC - O(m+n)

// s1 - bst to inorder vector for both trees 2 sorted vectors
// s2 - merge sorted vectors in 1 single sorted vector
// s3 - from inorder sorted vector make bst

// void inorder(Node* root , vector<int> &in){
//     if(!root)return ;

//     inorder(root->left , in);
//     in.push_back(root->data);
//     inorder(root->right , in);
// }

// vector<int> mergeArrays(vector<int> a , vector<int> b){
//     vector<int>ans(a.size() + b.size());

//     int i = 0 , j = 0;
//     int k = 0;
//     while(i < a.size() && j < b.size()){
//         if(a[i] < b[j])
//         {
//             ans[k++] = a[i];
//             i++;
//         }
//         else
//         {
//             ans[k++] = b[j];
//             j++;
//         }
//     }

//     while(i < a.size())
//     {
//         ans[k++] = a[i];
//         i++;
//     }

//     while(j < b.size())
//     {
//         ans[k++] = b[j];
//         j++;
//     }
//     return ans;
// }

// Node* inorderToBST(int start , int end , vector<int> &in)
// {
//     if(start > end)return NULL;

//     int mid = (start + end)/2;
//     Node* root = new Node(in[mid]);

//     root->left = inorderToBST(start , mid-1 , in);
//     root->right = inorderToBST(mid+1 , end , in);
//     return root;
// }

// Node* mergeBST(Node* root1 , Node* root2)
// {
//     vector<int> bst1 , bst2;
//     inorder(root1 , bst1);
//     inorder(root2 , bst2);

//     vector<int> mergeArray = mergeArrays(bst1 , bst2);

//     int start = 0 , end = mergeArray.size()-1;
//     return inorderToBST(start , end , mergeArray);
// }





// Approch 2 
// s1 - convert bst to sorted LL TC - O(n) SC-O(h)
// s2 - merge 2 sorted LL
// s3 - sorted LL to a BST

void convertIntoSortedDLL(Node* root , Node* &head)
{
    if(root == NULL)return ;

    convertIntoSortedDLL(root->right , head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left , head);
}

Node* mergeLinkedList(Node* head1 , Node* head2)
{
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data < head2 -> data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }

        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int cntNodes(Node* head)
{
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLLToBST(Node* &head , int n)
{
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node* left = sortedLLToBST(head , n/2);
    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head , n-n/2-1);
    return root;
}

Node* mergeBST(Node* root1 , Node* root2)
{

    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

    Node* head1 = NULL;
    convertIntoSortedDLL(root1 , head1);
    if (head1 != NULL) head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2 , head2);
    if (head2 != NULL) head2->left = NULL;

    Node* head = mergeLinkedList(head1 , head2);

    return sortedLLToBST(head , cntNodes(head));
}

int main(){
    Node* root1 = NULL;
    cout<<"Enter data to create BST 1"<<endl<<endl;
    // 5 3 6 2 4 -1
    takeInput(root1);
    cout<<endl<<endl;

    levelOrderTraversal(root1);

    Node* root2 = NULL;
    cout<<"Enter data to create BST 1"<<endl<<endl;
    // 2 1 3 7 6 -1
    takeInput(root2);
    cout<<endl<<endl;

    levelOrderTraversal(root2);

    cout<<endl<<endl;

    Node* root = mergeBST(root1 , root2);

    levelOrderTraversal(root);    

    return 0;
}