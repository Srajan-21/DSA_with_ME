#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> arr{4,2,4,4,4};

    for(int i=0;i<arr.size();i++)
    {
        int index=abs(arr[i]);
        if(arr[index-1]>0)
        arr[index-1]*=-1;
    }

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>0)
        cout<<i+1<<" ";
    }
    
    return 0;
}

