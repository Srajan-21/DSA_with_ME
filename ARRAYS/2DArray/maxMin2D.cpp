#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int arr[4][3]={{-1,5,2},
                   {9,6,8},
                   {6,5,-9},
                   {5,6,8}};
                   
    int rows=4;
    int col=3;

    int max=INT_MIN;
    int min=INT_MAX;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]>max)
            {
            max=arr[i][j];
            }
            if(arr[i][j]<min)
            {
            min=arr[i][j];
            }
        }
    }











    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<col;j++)
    //     {
    //         if(arr[i][j]>max)
    //         {
    //             max=arr[i][j];
    //         }
    //     }
    // }

    cout<<"Maximum:"<<max<<endl;

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<col;j++)
    //     {
    //         if(arr[i][j]<min)
    //         {
    //             min=arr[i][j];
    //         }
    //     }
    // }

    cout<<"Minimum:"<<min;
}
