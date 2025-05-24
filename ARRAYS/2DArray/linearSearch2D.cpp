#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][3]={{1,5,2},
                   {5,6,8},
                   {6,5,9}};
                   
    int rows=4;
    int col=3;
    int key=0,flag=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==key)            
            {
                flag=1;
            }
        }
    }

    if(flag==1)
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
}