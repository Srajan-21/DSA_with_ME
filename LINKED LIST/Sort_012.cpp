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
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void sort_count(Node* &head)
{
    //find Number of zeroes ones and twos
    int zero = 0;
    int one = 0;
    int two = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else if(temp->data == 2)
            two++;
        temp = temp->next;
    }

    temp = head;
    while(zero--)
    {
        temp -> data = 0;
        temp = temp->next;
    }

    while(one--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while(two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node* sort_approach2(Node* &head){

    //create dummy nodes -1
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* onetail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //Traverse original Linked List and add it in particular 0 1 and 2 linked lists
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr -> data == 0){
            //take out zero node 
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //Append zero node in zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr -> data == 1){
            //take out one node 
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append one node in oneHead LLL
            onetail->next = temp;
            onetail = temp;
        }
        else if(curr -> data == 2){
            //take out two node 
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append one node in oneHead LLL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    //we got zero , one and two LinkedLists 
    //we wil join them 
    //remove dummy nodes

    //we wiill modify one linkedList we will dlete originnal onehead and shift it to next node
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

     //we wiill modify two linkedList we will dlete originnal onehead and shift it to next node
     temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;


    //we will join zero list with one LL
    if(oneHead != NULL){
        //one lsit id non empty
        zeroTail->next = oneHead;
        if(twoHead != NULL)
            onetail->next = twoHead;
    }
    else{
        //one list is empty
        if(twoHead!=NULL)
            zeroTail->next=twoHead;
    }

    //remove zerohead dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;


    //return modified zerohead
    return zeroHead;

}

int main(){
    Node* first =  new Node(1);
    Node* second = new Node(2);
    Node* third =  new Node(2);
    Node* fourth = new Node(1);
    Node* fifth =  new Node(2);
    Node* sixth =  new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout<<"Input Linked List : ";
    print(first);

    cout<<endl;

    // sort_count(first);
    Node* head = sort_approach2(first);
    cout<<"Output : ";
    print(head);
}