#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> arr{1,2,3,4,5,3,5,6,4,2,1,5,2};
    int sum=6;

    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            for(int k=j+1;j<arr.size();j++)
            {
                if(arr[i]+arr[j]+arr[k]==sum)
                cout<<"Pair : ("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
            }
        }
    }
    return 0;
}