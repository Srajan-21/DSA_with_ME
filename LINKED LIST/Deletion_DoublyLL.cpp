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

    ~Node(){
        cout<<"Node with Value : "<<this->data<< " Deleted"<<endl;
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
    if(head == NULL){
        cout<<"Already Empty"<<endl;
        return;
    }

    if(head == tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(Node* &head , Node* &tail){
    if (tail == NULL) return;

    // Single node
    if (head == tail) {
        delete tail;
        head = NULL;
        tail = NULL;
        return;
    }

     Node* temp = tail;
     tail = tail->prev;
     temp->prev = NULL;
     tail->next = NULL;
     delete temp;
}

void deleteAtPosition(Node* &head , Node* &tail , int position){
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    if(head->next == NULL){
        // single nod in linked list
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    
    if(position > len || position <= 0)
    {
        cout<<"Enter a valid Position"<<endl;
        return;
    }

    // Delete at Head
    if(position == 1){
        deleteAtHead(head , tail);
        return;
    }

    // Delete at Tail
    if(position == len){
        deleteAtTail(head , tail);
        return;
    }

    int i=1;
    Node* left = head;
    while(i<position-1)
    {
        left=left->next;
        i++;
    } 
    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
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

    cout<<endl;
    deleteAtPosition(head , tail , 3);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtPosition(head , tail , 4);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtPosition(head , tail , 4);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    deleteAtPosition(head , tail , 0);
    cout<<"Length:"<<getLength(head)<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;


}
