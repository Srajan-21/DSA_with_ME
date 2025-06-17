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

Node* getMiddle(Node* head){
    // TC - O(n/2)
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return head;
    }

    if(head->next == NULL){
        // Only one node in LL
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

Node* Middle(Node* head)
{
    int len = findLength(head);
    Node* temp = head;
    int n = len / 2;
    if(len % 2 == 0)
    {
        int i=1;
        while(i!=n)
        {
            temp = temp->next;
            i++;
        }

        return temp;
    }
    else{
        int i=1;
        while(i!=n)
        {
            temp = temp->next;
            i++;
        }

        return temp -> next;
    }
}


 
int main(){
   
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
    cout<<endl;

    int middle = Middle(head) -> data;
    cout<<"Middle:"<<middle;

    return 0;
}