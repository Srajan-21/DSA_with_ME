#include <iostream>
using namespace std;

class Node{
    public:
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
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
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

void deleteAtHead(Node* &head , Node* &tail){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(Node* &head , Node* &tail){
     Node* temp = tail;
     tail = tail->prev;
     temp->prev = NULL;
     tail->next = NULL;
     delete temp;
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
    insertAtTail(head , tail , 9);
    insertAtTail(head , tail , 10);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtHead(head , tail);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtTail(head , tail);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtHead(head , tail);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtTail(head , tail);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

}
