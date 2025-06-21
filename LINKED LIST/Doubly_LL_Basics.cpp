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

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    // TC - O(n)
    // SC - O(n)
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* &head)
{
    // TC - O(n)
    // SC - O(n)
    int len = 0;
    Node*temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}


int main(){
    Node* first = new Node(3);
    Node* second = new Node(2);
    Node* third = new Node(1);

    first -> next = second;
    second -> prev = first;

    second -> next = third;
    third -> prev = second;

    print(first);
}
