#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][3]={{1,5,2},
                   {5,6,8},
                   {6,5,9},
                   {5,6,8}};
                   
    int rows=4;
    int col=3;

    cout<<"row wise sum"<<endl;

    for(int i=0;i<rows;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            sum+=arr[i][j];
        }
        cout<<"Sum of "<<i<<"th row = "<<sum<<endl;
    }




cout<<"colm wise sum"<<endl;


    for(int i=0;i<col;i++)
    {
        int sum=0;
        for(int j=0;j<rows;j++)
        {
            sum+=arr[j][i];
        }
        cout<<"Sum of "<<i<<"th col:"<<sum<<endl;
    }
}