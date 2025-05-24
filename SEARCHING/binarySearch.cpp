#include <iostream>
using namespace std;

int binarySearch( int arr[] , int size , int target)
{
    int start=0;
    int end=size-1;

    while(start<=end)
    {
            int mid=start+(end-start)/2;

        int element=arr[mid];
         
        if(element==target)
        {
            return mid;
        }

        else if (target<element)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }        
    }
    return -1;
}

void printSearchResult(int target, int index) {
    if (index == -1)
        cout << target << " not found" << endl;
    else
        cout << target << " found at index " << index << endl;
}

int main(){
    int arr[] = {1,2,4,16,32,64,128};
    int size = sizeof(arr)/sizeof(int);
    int targets[] = {64, 16, 17};

    for (int target : targets) {
        printSearchResult(target, binarySearch(arr, size, target));
    }

    
    return 0;
}