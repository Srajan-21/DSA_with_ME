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
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insert(Node* &head,int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int main(){
    Node* head = new Node(10);
    insert(head,20);
    insert(head,30);
    insert(head,20);    
    insert(head,20);

    print(head);
    return 0;
}