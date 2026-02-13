#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// O(nlogk) time complexity 
// k = number of sorted arrays
// N = total number of elements present in all arrays combined

class Node{
    public: 
    int data;
    int i;
    int j;

    Node(int data , int row , int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(Node* a , Node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&arrs , int k)
{
    priority_queue<Node* , vector<Node*> , compare>minHeap;

    // step 1 : insert first elements of all arrays
    for(int i = 0 ; i < k ; i++)
    {
        Node* temp = new Node(arrs[i][0] , i , 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // step2
    while(minHeap.size() > 0)
    {
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < arrs[i].size())
        {
            Node* next = new Node(arrs[i][j+1] , i , j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arrs = {{1,4,5},{1,3,4},{2,4,6}};
    int k = 3;

    vector<int>ans = mergeKSortedArrays(arrs , k);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}