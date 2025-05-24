#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>>v{{1,2,3,4},
                         {5,6,7,8},
                         {9,8,7,6}};
    int rows=v.size();
    int cols=v[0].size();


    // Columnwise Wave top to bottom bottm to top
    cout<<"Column wise "<<endl;
    for(int startCol=0;startCol<cols;startCol++)
    {
        if(startCol%2==0)
        {
            for(int startRow=0;startRow<rows;startRow++)
            {
                cout<<v[startRow][startCol]<<" ";
            }
        }
        else
        {
            for(int startRow=rows-1;startRow>=0;startRow--)
            {
                cout<<v[startRow][startCol]<<" ";
            }
        }
    }


    // Row wise Wave 
    cout<<endl;
    cout<<"Row wise "<<endl;
    for(int startRow=0;startRow<rows;startRow++)
    {
        if(startRow%2==0)
        {
            for(int startCol=0;startCol<cols;startCol++)
            {
                cout<<v[startRow][startCol]<<" ";
            }
        }
        else
        {
            for(int startCol=cols-1;startCol>=0;startCol--)
            {
                cout<<v[startRow][startCol]<<" ";
            }
        }
    }

    return 0;
}

