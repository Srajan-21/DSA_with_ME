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

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* fwd = curr->next;
    while(curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

bool palindrome(Node* head)
{
    if(head == NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }

    if(head->next == NULL)
    {
        return true;
    }

    // find middle node of linked list
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
    }

    // slow pointer is pointng to middle of LL
    // reverse LL after middle/slow node
    Node* reverseHead = reverse(slow->next);
    slow->next = reverseHead;

    // start comparing
    Node* temp1 = head;
    Node* temp2 = reverseHead;
    while(temp2 != NULL){
        if(temp1->data != temp2->data)
        {
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    // Node* sixth = new Node(2);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = sixth;

    bool isPalindrome = palindrome(first);
    if(isPalindrome)
        cout<<"Palindrome";
    else
        cout<<"NO";
}