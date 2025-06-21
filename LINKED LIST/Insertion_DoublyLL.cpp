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

void insertAtPosition(Node* &head , Node* &tail , int data , int position){

    int len = getLength(head);

    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        insertAtHead(head , tail , data);
        return;
    }

    if(position > len){
        insertAtTail(head , tail , data);
        return;
    }

    int i = 1;
    Node* prevNode = head;
    while(i<position-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;

    Node* newNode = new Node(data);
    prevNode->next = newNode;
    newNode->next = currNode;
    currNode->prev = newNode;
    newNode->prev = prevNode;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head , tail , 9);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    insertAtHead(head , tail , 5);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    insertAtHead(head , tail , 8);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    insertAtTail(head , tail , 6);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    insertAtHead(head , tail , 3);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    insertAtTail(head , tail , 1);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    insertAtHead(head , tail , 9);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    insertAtPosition(head , tail , 101 , 3);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    insertAtPosition(head , tail , 101 , 1);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    insertAtPosition(head , tail , 301 , 5);
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
}