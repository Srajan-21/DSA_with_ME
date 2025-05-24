//     * 
//    * *
//   *   *
//  *     *
// *       *
// *       *
//  *     *
//   *   *
//    * * 
//     *



#include <iostream>
using namespace std;;

int main(){
    
    int rows;

    cout<<"Enter rows:";
    cin>>rows;

    // PYRAMID

    for(int i = 0 ; i < rows ; i++)
    {
        for(int space = 0 ; space < rows-i-1 ; space++)
        {
            cout<<" ";
        }

        for(int j = 0 ; j < ((2*i)+1) ; j++)
        // for(int j = 0 ; j < i+1 ; j++)
        {
            if(j==0 || j==2*i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }  

        cout<<endl;
    }   

    // INVERTED PYRAMID

    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            cout<<" ";
        }
        for(int j = 0 ; j < 2*(rows-i)-1 ; j++)
        // for(int j = 0 ; j < rows-i ; j++)
        {
             if(j==0 || j==2*(rows-i)-2){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        
        cout<<endl;
    }    
}
