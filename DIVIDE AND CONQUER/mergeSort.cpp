#include <iostream>
using namespace std;

void merge(int* arr,int s,int e){
    int mid = (s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    // dynamically array creation
    // arrays left and right created with len1 len2 sizes
    int* leftArr = new int[len1];
    int* rightArr= new int[len2];

    // copy values
    int k=s;
    for(int i=0;i<len1;i++)
    {
        leftArr[i] = arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        rightArr[i]=arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrIndex = s;

    while(leftIndex < len1 && rightIndex < len2)
    {
        if(leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrIndex++] = leftArr[leftIndex++];
        }
        else 
        {
            arr[mainArrIndex++] = rightArr[rightIndex++];
        }
    }

    // copy logic for left Array
    while(leftIndex < len1)
    {
        arr[mainArrIndex++] = leftArr[leftIndex++];
    }

    // copy logic for right Array
    while(rightIndex < len2)
    {
        arr[mainArrIndex++] = rightArr[rightIndex++];
    }
}

void mergeSort(int * arr , int s , int e)
{
    // base case
    // s==e single array
    // s>e invalid array 
    if(s>=e)
        return ;

    int mid= (s+e)/2;

    // left part sort kro recursion se
    mergeSort(arr,s,mid);
    // right part sort kro recursion se
    mergeSort(arr,mid+1,e);
    // merge kro sorted arrays
    merge(arr,s,e);
}

int main(){
    int arr[]={4,5,13,2,12,1,5,6,4,7,89,9,6,2,4,56,2,3,5,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    int s=0;
    int e=n-1;

    // call merge Sort
    mergeSort(arr,s,e);

    // print sorted array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}