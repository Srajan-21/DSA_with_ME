#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][3]={{1,5,2},
                   {5,6,8},
                   {6,5,9}};

    cout<<"row wise"<<endl;
    for(int i=0;i<3;i++)               
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
    cout<<"column wise"<<endl;
    
    for(int i=0;i<3;i++)               
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[j][i]<<" ";
        }
    }                  
    
}