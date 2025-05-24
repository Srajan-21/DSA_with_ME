#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int min=INT_MAX;
    int max=INT_MIN;

    int arr[]={3,6,5,4,8,9,26,5};
    int length=sizeof(arr)/sizeof(int);

    for(int i=0;i<length;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }

    cout<<"MAX:"<<max<<endl;
    cout<<"MIN:"<<min;

}