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

void deleteLink(Node* head , int M , int N){
    if(!head) return;
    Node* it = head;

    for(int i=0 ; i<M-1 ; i++){
        // if M nodes are NA
        if(!it)return;
        it = it->next;
    }

    // it would be at Mt Node
    if(!it)return;

    Node* MthNode = it;
    it = MthNode->next;
    for (int i = 0; i< N ; i++){
        if(!it)break;

        Node* temp = it->next;
        delete it;
        it = temp;
    }

    MthNode->next = it;
    deleteLink(it , M , N);
}


int main(){
    Node* head1   = new Node(5);
    Node* second1 = new Node(7);
    Node* third1  = new Node(8);
    Node* fourth1 = new Node(30);
    Node* head2   = new Node(10);
    Node* second2 = new Node(20); 
    Node* head3   = new Node(19);
    Node* second3 = new Node(22);
    Node* third3  = new Node(50);
   
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = head2;
    head2->next = second2;
    second2->next = head3;
    head3->next = second3;
    second3->next = third3;

    
    print(head1);
    cout<<endl;
    deleteLink(head1 , 3 , 1);
    print(head1);
    
    
    return 0;
}