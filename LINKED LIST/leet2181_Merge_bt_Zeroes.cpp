#include <iostream>
#include <vector>
#include <limits.h>
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

Node* merge(Node* head){
    if(!head)return 0;

    Node* slow = head , *fast = head->next , *newLastNode = NULL;
    int sum = 0;
    while(fast){
        if(fast->data != 0){
            sum += fast->data;
        }
        else{
            slow->data = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }

    Node* temp = newLastNode->next;
    newLastNode->next = NULL;

    while(temp){
        Node* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    return head;
}


int main(){
    Node* first   = new Node(0);
    Node* second  = new Node(3);
    Node* third   = new Node(6);
    Node* fourth  = new Node(0);
    Node* fifth   = new Node(5);
    Node* sixth   = new Node(5);
    Node* seventh = new Node(0);
   
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
 
    Node* head = first;
    cout<<"Printing Linked List"<<endl;
    print(first);
    cout<<endl;

    Node* temp = merge(head);
    print(temp);

   return 0 ;
}