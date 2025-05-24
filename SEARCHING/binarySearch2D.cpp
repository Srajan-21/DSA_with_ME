#include <iostream>
using namespace std;

int binarySearch( int arr[][3] , int rows , int cols , int target)
{
    int start=0;
    int end=rows*cols-1;

    while(start<=end)
    {
         int mid=start+(end-start)/2;
         int rowIndex=mid/cols;
         int colIndex=mid%cols;

        int element=arr[rowIndex][colIndex];
         
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

int main(){
    int arr[4][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9},
                   {10,11,12}};
    int rows = 4;
    int cols = 3;
    int target = 6;

    cout<<"iindex"<<binarySearch(arr,rows,cols,target);
    return 0;
}