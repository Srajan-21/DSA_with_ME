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

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left , Node* right){
    if(left == 0)
        return right;
    if(right == 0)
        return right;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left && right){
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

    if(left){
        temp->next = left;
        // temp = left;
        // left = left->next;
    }
    if(right){
        temp->next = right;
        // temp = right;
        // right = rigt->next;
    }

    return ans->next;
}

Node* sort(Node* head){
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    //Break LL into two alves using mid node
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //sort RE
    left = sort(left);
    right = sort(right);

    //merge borth left and right sorted LL
    Node* mergedLL = merge(left , right);
    return mergedLL;
}

int main(){
    Node* head   = new Node(-1);
    Node* second = new Node(5);
    Node* third  = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth  = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
   
    
    print(head);
    cout<<endl;
    // print(head2);
    cout<<endl;

    Node* temp = sort(head);
    // cout<<temp->data;
    print(temp);
    
    return 0;
}