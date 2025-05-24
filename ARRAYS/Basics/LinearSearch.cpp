#include <iostream>
using namespace std;

int main()
{
    int arr[]={1,5,2,3,6,4,2,8};
    int size = 8;
    int key=1;

    bool flag=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            break;
        }
    }

    if(flag)
    {
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }

    return 0;
}