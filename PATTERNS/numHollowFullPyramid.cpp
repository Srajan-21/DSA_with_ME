//     1
//    1 2
//   1   3
//  1     4
// 1 2 3 4 5
        


#include <iostream>
using namespace std;;

int main(){
    
    int rows;
 
    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0 ; i < rows ; i++)
    {

        for(int j = 0 ; j < rows - i - 1 ; j++)
        {
            cout<<" ";
        }

        if( i == rows - 1)
        {
            for(int j = 0 ; j < rows ; j++ )
            {
                cout<<j+1<<" ";
            }
        }
        else{
             for(int j = 0 ; j < 2*i+1 ; j++ )
            {
                if(j==0)
                {
                    cout<<1;
                }
                else if(j==(2*i))
                {
                    cout<<i+1;
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        cout<<endl;

    }

    
}