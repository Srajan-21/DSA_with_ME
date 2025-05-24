#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v,int s,int e,int target)
{
    if(s>e)
        return -1;

    int mid=(s+e)/2;

    if(v[mid]==target)
    return mid;

    if(v[mid]<target)
    return binarySearch(v,mid+1,e,target);
    else
    return binarySearch(v,s,mid-1,target);
}

int main()
{
    vector<int> v{10,20,30,40,50,60,70,80};
    int n=v.size();

    int s=0;
    int e=n-1;
    int target=70;
    cout<<binarySearch(v,s,e,target);
}