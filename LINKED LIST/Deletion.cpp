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
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}

void deletionAtHead(Node* &head)
{
    if(head == NULL)
    {
        cout<<"Cannot Delete , Linked List is empty"<<endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deletionAtTail(Node* &head , Node* &tail)
{
    int len = length(head);

    // if one node
    if(head==tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
        return;
    }

    int i = 1;
    Node* prev = head;
    while(i<len-1)
    {
        prev = prev->next;
        i++;
    }

    prev->next = NULL;
    Node* temp = tail;
    tail = prev;
    delete temp;
}

void deletionAtPosition(Node* &head , Node* &tail , int position)
{
    int len = length(head);


    if(position == 0)
    {
        deletionAtHead(head);
        return;
    }

    if(position>=len)
    {
        deletionAtTail(head,tail);
        return;    
    }

    int i = 1;
    Node* prev = head;
    while(i<position-1)
    {
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);
    Node* seventh = new Node(7);
    Node* eighth = new Node(8);

    Node* head = first;
    Node* tail = eighth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth; 

    cout<<"Printing Linked List before Deletion"<<endl;
    print(head);

    cout<<endl;
    cout<<endl;

    deletionAtHead(head);
    cout<<"After Deletion"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    cout<<endl;
    cout<<endl;

    deletionAtTail(head , tail);
    cout<<"After Deletion"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    cout<<endl;
    cout<<endl;

    deletionAtPosition(head , tail , 3);
    cout<<"After Deletion"<<endl;
    print(head);
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    
    return 0;
}