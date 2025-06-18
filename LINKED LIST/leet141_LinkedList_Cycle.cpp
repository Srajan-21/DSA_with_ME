#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node * next;

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

bool checkForLoop(Node* &head){
    if(head == NULL){
        cout<<"LL is Empty"<<endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL)
    {
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            // loop present
            return true;
        }
    }
    // fast reached null no loop present
    return false;
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
    Node* ninth = new Node(9);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fifth;

    Node* head = first;
    // cout<<"Printing Linked List"<<endl;
    // print(first);

    cout<<"Loop present or not : "<<checkForLoop(head)<<endl;

}