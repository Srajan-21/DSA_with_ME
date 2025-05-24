#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr{1,0,1};

    int left=0,right=arr.size()-1;
    int i=0;

    // 2 pointer approach

    // while(i!=right)
    // {
    //     if(arr[i]==0)
    //     {
    //         swap(arr[left],arr[i]);
    //         left++;
    //         i++;
    //     }
    //     else{
    //         swap(arr[right],arr[i]);
    //         right--;
    //     }
    // }

    while(left<right)
    {
        if(arr[left]==0)          
        {
            left++;
        }
        else{
            swap(arr[left],arr[right]);
            right--;
        }
    }

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    
    return 0;
}