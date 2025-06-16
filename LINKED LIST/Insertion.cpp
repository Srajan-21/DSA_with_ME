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

void insertAtHead(Node* &head , Node* & tail , int data)
{
    // if(head == NULL)
    // {
    //     Node* newNode = new Node(data);
    //     head = newNode;
    //     tail = newNode;
    // }else{
    //     Node* newNode = new Node(data);
    //     newNode->next = head;
    //     head = newNode;
    // }

    // return use krenge to - Best Practice 
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    // not good practice
    // // nyi node banegi jo insert krni h
    // Node* newNode = new Node(data);
    // // nyi node ka jo next oga vo current head ko point krega
    // if(head == NULL)
    // {
    //     tail = newNode; //tail pointer update krne k liye ye if condition likhenge 
    // }
    // newNode->next = head;
    // // head ko update krke nyi node pe laa denge
    // head = newNode;
}



int main(){
    // Node* head = new Node(10);
    //agar head pe insert krte jana h tb hi ye use krenge
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,1);
    insertAtHead(head,tail,3);
    
    print(head);
    return 0;
}