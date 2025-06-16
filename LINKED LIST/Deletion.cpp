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
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
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

void deletionAtTail(Node* & head , Node* tail)
{
    int len = length(head);

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

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Printing Linked List before Deletion"<<endl;
    print(first);

    cout<<endl;
    cout<<endl;

    deletionAtHead(first);
    cout<<"After Deletion"<<endl;
    print(first);

    cout<<endl;
    cout<<endl;

    deletionAtTail(first , fifth);
    cout<<"After Deletion"<<endl;
    print(first);

    return 0;
}