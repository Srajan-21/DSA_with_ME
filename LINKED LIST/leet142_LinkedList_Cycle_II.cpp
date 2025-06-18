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

Node* startOfLoop(Node* &head){

    if(head == NULL || head->next==NULL)
            return NULL;

        Node* slow = head;
        Node* fast = head;

        bool hasCycle = false;
        while(fast != NULL && fast->next!=NULL)
        {
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }

            if(slow == fast){   
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle)
            return NULL;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    


    //In the first while(fast != NULL) loop, you break only if slow == fast, but don’t check if fast == NULL after moving it twice. This could cause a segmentation fault.

    // Also, if no cycle is found, you still proceed to the second loop, which results in undefined behavior.
    // if(head == NULL){
    //     cout<<"LL is Empty"<<endl;
    //     return NULL;
    // }

    // Node* slow = head;
    // Node* fast = head;

    // while(fast != NULL)
    // {
    //     fast = fast -> next ;
    //     if(fast != NULL){
    //         fast = fast->next;
    //         slow = slow->next;
    //     }

    //     if(slow == fast){
    //         slow = head;
    //         break;
    //     }
    // }
    
    // while(slow != fast)
    // {
    //     slow = slow->next;
    //     fast = fast->next;
    // }

    // return slow;
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
    ninth->next = sixth;

    Node* head = first;
    // cout<<"Printing Linked List"<<endl;
    // print(first);

    // cout<<"Loop present or not : "<<checkForLoop(head)<<endl;

    cout<<"start of loop : "<<startOfLoop(head)->data<<endl;


}