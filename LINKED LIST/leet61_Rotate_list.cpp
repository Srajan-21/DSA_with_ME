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

    ~Node(){
        cout << "Memory freed for node with data " << this->data << endl;
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

Node* rotate(Node* head , int k){
    if(head == NULL)return NULL;

    int len = length(head);
    int actualRotateK = k % len;
    if(actualRotateK == 0)return head;
    int newLastNodePos = len-actualRotateK-1;
    Node* newLastNode = head;
    for(int i=0 ; i<newLastNodePos ; i++){
        newLastNode = newLastNode->next;
    }

    Node* newHead = newLastNode->next;
    newLastNode->next = NULL;

    Node* temp = newHead;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}

int main(){
    Node* first = new Node(11);
    Node* second = new Node(22);
    Node* third = new Node(33);
    Node* fourth = new Node(44);
    Node* fifth = new Node(55);
    Node* sixth = new Node(66);
    Node* seventh = new Node(77);
    Node* eighth = new Node(88);

    Node* head = first;
    Node* tail = eighth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth; 

    print(head);
    cout<<endl;
    
    Node* temp = rotate(head , 5);
    print(temp);
    return 0;
}