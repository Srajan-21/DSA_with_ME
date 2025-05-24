#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    vector <int> arr{1,2,3,6,5,4,8,9,2,3,5,1};
    vector <int> brr{66,2,35,5,4,4,11};

    vector <int> ans;
    int element;

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<brr.size();j++)
        {
            if(arr[i]==brr[j])
            {
                // arr[i]=INT_MIN;
                brr[j]=INT_MIN;
                ans.push_back(arr[i]);
                break; 
            }
        }
    }

    for(auto value:ans)
    {
        cout<<value<<" ";
    }

}