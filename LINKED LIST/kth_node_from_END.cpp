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

    ~Node(){
        cout << "Memory freed for node with data " << this->data << endl;
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

void kth_Node_Recursion(Node* head , int &pos , int &ans)
{
    if(head == 0) 
        return;

    kth_Node_Recursion(head->next , pos , ans);
    if(pos == 1){
        ans = head->data;
    }
    pos--;
}

int getNode(Node* head , int pos){
    int ans = -1;
    kth_Node_Recursion(head , pos , ans);
    return ans;
}

Node* kth_Node_Length(Node* head , int pos){
    int len = length(head);
    int posFront = len-pos+1;
    Node* temp = head;
    int i=1;
    while(i!=posFront){
        temp = temp->next;
        i++;
    }
    return temp;
}

int main(){
    Node* first = new Node(11);
    Node* second = new Node(22);
    Node* third = new Node(33);
    Node* fourth = new Node(44);
    Node* fifth = new Node(55);
    Node* sixth = new Node(66);
    Node* seventh = new Node(77);
    Node* eighth = new Node(88);

    Node* head = first;
    Node* tail = eighth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth; 

    print(head);
    cout<<endl;
    cout<<getNode(head , 7);
    // Node* temp = kth_Node_Length(head , 4);
    // cout<<temp->data;
    // print(head);
    return 0;
}