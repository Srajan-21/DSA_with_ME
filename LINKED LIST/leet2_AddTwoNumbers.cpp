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

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* reverse(Node* &head){
   Node* prev = NULL;
   Node* curr = head;
   while(curr!=NULL)
   {
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp; 
   }
   return prev;
}

Node* add(Node* head1 , Node* head2){
    // reverse both LLs
    head1 = reverse(head1);
    head2 = reverse(head2);

    //add both LLs
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(head1 != NULL && head2 != NULL)
    {
        //calculate sum
        int sum = carry + head1->data + head2->data;
        //find digit to create node
        int digit = sum%10;
        //calculate carry
        carry = sum/10;

        //create new node for digit
        Node* newNode = new Node(digit);
        //attachh newNode into answer Linked List
        if(ansHead == NULL)
        {
            //first node insert in answer LL
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1 != NULL){
        int sum = carry + head1->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }

    while(head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    ansHead = reverse(ansHead);
    return ansHead;
}

int main(){
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    Node* third1 = new Node(9);

    head1->next = second1;
    second1->next = third1;


    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    // Node* third2 = new Node(4);
    head2->next = second2;
    // second2->next = third2;

    cout<<"1st Linked List : ";
    print(head1);
    cout<<endl;
    cout<<"2nd Linked List : ";
    print(head2);

    cout<<endl;
    Node* temp = add(head1,head2);
    cout<<"sum Linked List : ";
    print(temp);
}