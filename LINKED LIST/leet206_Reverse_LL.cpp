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

Node* reverse_Loop(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr -> next; //keep track of LL
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* reverse_Recursion(Node* &prev , Node* curr)
{
    if(curr == NULL)
        return prev ; 

    Node* forward = curr->next;
    curr->next = prev;

    // recursive call
    reverse_Recursion(curr , forward);

    // othher approach
    // Node* forward = curr -> next;
    // curr -> next = prev;
    // prev = curr;
    // curr = forward;
    // reverse_Recursion(prev , curr);
}

 
int main(){
    // Node* head = new Node(10);
    //agar head pe insert krte jana h tb hi ye use krenge
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head , tail , 1);
    insertAtTail(head , tail , 41);
    insertAtTail(head , tail , 12);
    insertAtTail(head , tail , 13);
    insertAtTail(head , tail , 26);
    insertAtTail(head , tail , 64);
    insertAtTail(head , tail , 32);
    insertAtTail(head , tail , 101);

    print(head);

    // Reversing Linked List
    Node* prev = NULL;
    Node* curr = head;
    // head = reverse_Loop(head);
    // cout<<endl;
    // print(head);
    cout<<endl;
    head = reverse_Recursion(prev , curr);
    cout<<endl;
    print(head);
    cout<<endl;

    return 0;
}