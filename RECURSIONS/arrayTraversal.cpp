#include <iostream>
using namespace std;

void print(int arr[],int i,int n)
{

    // base case
    if(i>=n)
    {
        return;
    }

    cout<<arr[i]<<" ";

    print(arr,++i,n);

}
int main()
{
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int i=0; //index
    print(arr,i,n);
}