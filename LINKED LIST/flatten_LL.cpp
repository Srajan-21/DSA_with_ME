#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->bottom = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->bottom;
    }
}

Node* merge(Node* a , Node* b){
    if(a==NULL) return b;
    if(!b) return a;

    Node* ans = 0;
    if(a->data < b->data){
        ans = a;
        a->bottom = merge(a->bottom , b);
    }
    else{
        ans = b;
        b->bottom = merge(a , b->bottom);
    }
    return ans;
}

Node* flatten(Node* head){
    if(head == NULL)return NULL;
    Node* mergedLL = merge(head , flatten(head->next));
    return mergedLL;
}


int main(){
    Node* head1   = new Node(5);
    Node* second1 = new Node(7);
    Node* third1  = new Node(8);
    Node* fourth1 = new Node(30);

    head1->bottom = second1;
    second1->bottom = third1;
    third1->bottom = fourth1;

    Node* head2   = new Node(10);
    Node* second2 = new Node(20);
    
    head2->bottom = second2;

    Node* head3   = new Node(19);
    Node* second3 = new Node(22);
    Node* third3  = new Node(50);

    head3->bottom = second3;
    second3->bottom = third3;

    Node* head4 = new Node(28);
    Node* second4 = new Node(35);
    Node* third4 = new Node(40);
    Node* fourth4 = new Node(45);

    head4->bottom = second4;
    second4->bottom = third4;
    third4->bottom = fourth4;

    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    
    Node* temp = flatten(head1);
    print(temp);
    // Node* temp = merge(head1 , head2);
    // cout<<temp->data;
    // print(temp);
    
    return 0;
}