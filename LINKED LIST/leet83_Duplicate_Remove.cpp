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

    Node(int data){
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


void removeDuplicate(Node* &head)
{
    // BABBAR
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->next != NULL && curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL; //good practice to make next NULL nahi lagayenge tab bhi sahi chlega 
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    // Node* temp1 = head;
    // Node* temp2 = head->next;
    // while(temp2 != NULL)
    // {
    // if(temp1->data == temp2->data && temp2!=NULL)
    // {
    //     temp1->next = temp2->next; 
    //     temp2 = temp2->next;
    // }
    // else{
    //     temp1 = temp1->next;
    //     // temp2 = temp2->next;
    // }
    // }
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(4);
    Node* sixth = new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(first);
    cout<<endl;

    removeDuplicate(first);
    print(first);
}