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
    Node* temp = head;
    while(temp != NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}

Node* Intersection_node(Node* head1 , Node*head2){
    Node* A = head1;
    Node* B = head2;

    while(A->next!=NULL && B->next!=NULL)
    {
        if(A == B)
            return A;

        A=A->next;
        B=B->next;
    }

    if(A->next == NULL && B->next == NULL && A != B)
        return NULL;

    if(A->next == NULL){
        //B LL is bigger or equal
        //find how much bigger
        int bLen = 0;
        while(B->next != NULL){
            bLen++;
            B = B->next;
        }
        while(bLen--)
        {
            head2 = head2->next;
        }
    }
    else{
        //A ll id bigger
        int aLen = 0;
        while(A->next != NULL){
            aLen++;
            A = A->next;
        }
        while(aLen--){
            head1 = head1->next;
        }
    }

    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}


int main(){
    Node* head1   = new Node(4);
    Node* second1 = new Node(1);
    Node* third1  = new Node(8);
    Node* fourth1 = new Node(4);
    Node* fifth1  = new Node(5);

    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;

    Node* head2   = new Node(5);
    Node* second2 = new Node(6);
    Node* third2  = new Node(1);
    

    head2->next = second2;
    second2->next = third2;
    third2->next = third1;
   
    
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;

    Node* temp = Intersection_node(head1 , head2);
    cout<<temp->data;
    
    return 0;
}