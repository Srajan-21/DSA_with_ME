#include <iostream>
using namespace std;

int main()
{
    int arr[3][3]={{1,5,2},
                   {5,6,8},
                   {6,5,9}};
                   
    int rows=3;
    int col=3;
    int t[3][3];

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            t[j][i]=arr[i][j];
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
}