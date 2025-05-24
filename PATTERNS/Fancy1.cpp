// 1
// 2*2
// 3*3*3
// 4*4*4*4
// 4*4*4*4
// 3*3*3
// 2*2
// 1



#include <iostream>
using namespace std;;

int main(){
    
    // int rows;

    // cout<<"Enter rows:";
    // cin>>rows;

    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < i+1 ; j++)
        {
            cout<<i+1;
            if(j!=i)
            {
                cout<<"*";
            }
        }
        cout<<endl;        
    } 

    for(int i = 0 ; i < 5 ; i++)   
    {
        for( int j = 0 ; j < 5 - i ; j++)
        {
            cout<<5-i;
            if(j!=5-i-1){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}