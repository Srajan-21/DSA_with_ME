// ********1********
// *******2*2*******
// ******3*3*3******
// *****4*4*4*4*****
// ****5*5*5*5*5****




#include <iostream>
using namespace std;;

int main(){
    
    int rows;

    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < (2*(rows-1))-i ; j++)
        {
            cout<<"*";
        }

        for(int j=0;j<i+1;j++)
        {
            if(j!=i){
            cout<<i+1<<"*";
            }
            else
            {
                cout<<i+1;
            }
        }

        for(int j = 0 ; j < (2*(rows-1))-i ; j++)
        {
            cout<<"*";
        }     
       cout<<endl;
    }

    
}