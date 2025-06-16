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

void print(Node* &head , Node* &tail)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int findLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
    

}

void insertAtHead(Node* &head , Node* & tail , int data)
{
    // if(head == NULL)
    // {
    //     Node* newNode = new Node(data);
    //     head = newNode;
    //     tail = newNode;
    // }else{
    //     Node* newNode = new Node(data);
    //     newNode->next = head;
    //     head = newNode;
    // }


    // return use krenge to - Best Practice 
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;


    // not good practice
    // // nyi node banegi jo insert krni h
    // Node* newNode = new Node(data);
    // // nyi node ka jo next oga vo current head ko point krega
    // if(head == NULL)
    // {
    //     tail = newNode; //tail pointer update krne k liye ye if condition likhenge 
    // }
    // newNode->next = head;
    // // head ko update krke nyi node pe laa denge
    // head = newNode;
}

void insertAtTail( Node* &head , Node* &tail , int data)
{
    // Best Practice
    if(tail == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;  
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;


    // Using Conditional Statement
    // if(tail == NULL)
    // {
    //     Node* newNode = new Node(data);
    //     head = newNode;
    //     tail = newNode;
    // }else{
    //     Node* newNode = new Node(data);
    //     tail->next = newNode;
    //     tail = newNode; 
    // }


    // not good practice
    // // nyi node banegi
    // Node* newNode = new Node(data);
    // // agar tail null hua to abhi tk LL empty h nyi node jo banegi to vahi hi phli node hogi to nyi node pe hi head aur tail hoga
    // if(tail == NULL) // null ka next nhi ho skta     
    // {
    //     head = newNode;
    //     tail = newNode;
    // }
    // // agar tail null nahi hua matlaba phle se LL me elements h to tail k next me add kr skte h
    // else{
    //     tail->next = newNode;
    // }
    // tail = newNode;
}

void insertAtPosition(Node* &head , Node* &tail , int data , int position)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 0)
    {
        insertAtHead(head,tail,data);
        return;
    }

    int len = findLength(head);
    if(position >= len)
    {
        insertAtTail(head,tail,data);
        return;
    }
    // Find Position of prev and curr pointer
    int i = 1;
    Node* prev = head;
    while(i<position)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}

int main(){
    // Node* head = new Node(10);
    //agar head pe insert krte jana h tb hi ye use krenge
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,12);
    insertAtHead(head,tail,1);
    insertAtTail(head,tail,21);
    insertAtTail(head,tail,24);
    insertAtHead(head,tail,3);

    print(head,tail);
    cout<<endl;
    cout<<"HEAD:"<<head->data<<endl;
    cout<<"TAIL:"<<tail->data<<endl;

    insertAtPosition(head,tail,301,7);
    
    print(head,tail);
    cout<<endl;
    cout<<"HEAD:"<<head->data<<endl;
    cout<<"TAIL:"<<tail->data<<endl;
    
    insertAtPosition(head,tail,301,0);
    
    print(head,tail);
    cout<<endl;
    cout<<"HEAD:"<<head->data<<endl;
    cout<<"TAIL:"<<tail->data<<endl;

    return 0;
}