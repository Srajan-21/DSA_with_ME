#include <iostream>
#include <vector>
#include <limits.h>
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

vector<int> nodesBwCritical(Node* head){
    vector<int> ans(2,-1);
    Node* prev = head;
    if(!prev)return ans;
    Node* curr = head->next;
    if(!curr)return ans;
    Node* nxt = head->next->next;
    if(!nxt)return ans;

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;

    while(nxt){
        bool isCP = ((curr->data > prev->data && curr->data > nxt->data) || (curr->data < prev->data && curr->data < nxt->data)) ? true : false;

        if(isCP && firstCP == -1){
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){
            minDist = min(minDist , i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }

    if(lastCP == firstCP){
        // only 1 cp found
        return ans;
    }
    else{
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

int main(){
    Node* first   = new Node(5);
    Node* second  = new Node(3);
    Node* third   = new Node(1);
    Node* fourth  = new Node(2);
    Node* fifth   = new Node(5);
    Node* sixth   = new Node(1);
    Node* seventh = new Node(2);
   
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
 
    Node* head = first;
    cout<<"Printing Linked List"<<endl;
    print(first);
    cout<<endl;

   vector<int> ans = nodesBwCritical(head);
   cout<<"min:"<<ans[0]<<endl;
   cout<<"max:"<<ans[1]<<endl;
   return 0 ;

}