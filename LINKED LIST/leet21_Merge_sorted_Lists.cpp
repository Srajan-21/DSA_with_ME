#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int length(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}

Node* merge(Node* left , Node* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return right;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left!=NULL && right!=NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if(left!=NULL){
        temp->next = left;
        // temp = left;
        // left = left->next;
    }
    if(right!=NULL){
        temp->next = right;
        // temp = right;
        // right = rigt->next;
    }

    return ans->next;
}


int main(){
    Node* head1   = new Node(1);
    Node* second1 = new Node(3);
    Node* third1  = new Node(5);

    head1->next = second1;
    second1->next = third1;

    Node* head2   = new Node(2);
    Node* second2 = new Node(4);
    Node* third2  = new Node(5);
    Node* fourth2  = new Node(6);
    Node* fifth2  = new Node(7);
    
    head2->next = second2;
    second2->next = third2; 
    third2->next = fourth2;
    fourth2->next = fifth2;  
    
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;

    Node* temp = merge(head1 , head2);
    // cout<<temp->data;
    print(temp);
    
    return 0;
}