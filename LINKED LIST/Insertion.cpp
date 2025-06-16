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

void insertAtHead(Node* &head,int data)
{
    // nyi node banegi jo insert krni h
    Node* newNode = new Node(data);
    // nyi node ka jo next oga vo current head ko point krega
    newNode->next = head;
    // head ko update krke nyi node pe laa denge
    head = newNode;
}

int main(){
    Node* head = new Node(10);
    // Node* head = NULL; //agar head pe insert krte jana h tb hi ye use krenge
    insertAtHead(head,20);
    insertAtHead(head,0);
    insertAtHead(head,920);    
    insertAtHead(head,200);
    insertAtHead(head,208);
    insertAtHead(head,30);
    insertAtHead(head,205);    
    insertAtHead(head,206);

    print(head);
    return 0;
}