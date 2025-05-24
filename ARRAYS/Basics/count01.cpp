#include <iostream>
using namespace std;

int main(){
    int key=2;
    int arr[]={1,2,3,5,1,2,6,5,4,7,8,9,6,5,2,1,4,5,6,9,8,7,4,2,3,6,5,4,1,5,6,9,8,7,5,2};
    int count=0;
    int length=sizeof(arr)/sizeof(int);

    for(int i=0;i<length;i++)
    {
        if(arr[i]==key)
        count++;
    }
    cout<<"No of "<<key<<"s in arr="<<count;
}