#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head , Node* &tail , int data){
    if(head == NULL){
        //DLL empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head , Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head , tail , 9);
    insertAtHead(head , tail , 5);
    insertAtHead(head , tail , 8);

    insertAtTail(head , tail , 6);
    insertAtHead(head , tail , 3);

    insertAtTail(head , tail , 1);
    insertAtHead(head , tail , 9);

    print(head);
}