// Very Important Question 
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

void print(Node* &head)
{
    // TC - O(n)
    // SC -O(1)
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int findLength(Node* &head)
{
    // TC - O(n)
    // SC -O(1)
    int len = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
    

}

void insertAtTail( Node* &head , Node* &tail , int data)
{
    // Best Practice
    if(tail == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;  
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* reverseKNodes(Node* &head , int k){
    if(head == NULL){
        // Empty Linked List
        return NULL;
    }

    int len = findLength(head);
    if(k > len)
    {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;

    while(count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = reverseKNodes(forward , k);
    }

    return prev;
}


int main(){
   
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head , tail , 1);
    insertAtTail(head , tail , 2);
    insertAtTail(head , tail , 3);
    insertAtTail(head , tail , 4);
    insertAtTail(head , tail , 5);
    insertAtTail(head , tail , 6);
    insertAtTail(head , tail , 7);
    insertAtTail(head , tail , 8);

    print(head);
    cout<<endl;

    head = reverseKNodes(head , 3);
    print(head);
    return 0;
}