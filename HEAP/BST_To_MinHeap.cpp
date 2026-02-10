#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Step 1: store inorder traversal (sorted values)
void inorder(Node* root, vector<int> &in) {
    if (!root) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Step 2: fill nodes in preorder to satisfy min heap
void convertToMinHeap(Node* root, vector<int> &in, int &index) {
    if (!root) return;

    root->data = in[index++];
    convertToMinHeap(root->left, in, index);
    convertToMinHeap(root->right, in, index);
}

Node* BSTToMinHeap(Node* root) {
    vector<int> in;
    inorder(root, in);

    int index = 0;
    convertToMinHeap(root, in, index);
    return root;
}

// For checking result
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

int main() {
    // BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Level order traversal of BST:\n";
    levelOrderTraversal(root);

    root = BSTToMinHeap(root);

    cout << "Level order traversal of Min Heap:\n";
    levelOrderTraversal(root);

    return 0;
}
