#include <iostream>
#include<vector>
#include<queue>
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

class compare{
    public:
    bool operator()(Node* a , Node* b)
    {
        return a->data > b->data;
    }
};

Node* mergeKSortedLists(vector<Node*>& arr)
{
    priority_queue<Node* , vector<Node*> , compare> minHeap;
    
    int k = arr.size();
    if(k == 0)return NULL;

    for(int  i = 0 ; i < k ; i++)
    {
        if(arr[i] != NULL)
        {
            minHeap.push(arr[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(minHeap.size() > 0)
    {
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL)
        {
            minHeap.push(top -> next);
        }

        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else{
            tail -> next = top;
            tail = top;
        }
    }
    return head;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    Node* head3 = new Node(2);
    head3->next = new Node(6);

    vector<Node*> arr;
    arr.push_back(head1);
    arr.push_back(head2);
    arr.push_back(head3);

    Node* head = mergeKSortedLists(arr);
    print(head);
}