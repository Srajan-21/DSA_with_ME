#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr , int n , int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
        largest = left;

    if(right <= n && arr[largest] < arr[right])
        largest = right;

    if(largest != i)
    {
        swap(arr[largest] , arr[i]);
        heapify(arr , n , largest);
    }
}

vector<int> mergeHeaps(vector<int> &a , vector<int>&b , int n , int m)
{
    // step1 : merge both arrays into one
    vector<int>ans;
    ans.push_back(-1);

    for(int i=1 ; i < a.size() ; i++)ans.push_back(a[i]);
    for(int i=1 ; i < b.size() ; i++)ans.push_back(b[i]);

    // step 2: build heap using merged array
    int size = ans.size();
    for(int i = size/2;i>0;i--)
    {
        heapify(ans,size-1,i);
    }

    return ans;
}

int main(){
    vector<int> a = {-1,10,5,6,2};
    vector<int> b = {-1,12,7,9};

    int n=a.size();
    int m=b.size();

    vector<int> ans = mergeHeaps(a,b,n,m);

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
    
}