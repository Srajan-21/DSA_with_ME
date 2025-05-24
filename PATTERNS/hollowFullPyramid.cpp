//    *
//   * *
//  *   *
// *******



#include <iostream>
using namespace std;;

int main(){
    
    int rows;

    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0 ; i < rows ; i++)
    {
        for(int space = 0 ; space < rows-i-1 ; space++)
        {
            cout<<" ";
        }

        for(int j = 0 ; j < ((2*i)+1) ; j++)
        // for(int j = 0 ; j < i+1 ; j++)
        {
            if(j==0 || j==2*i || i==rows-1 ){
            cout<<"*";
            }
            else{
                cout<<" ";
            }
        }       

       
        
        // for(int space = 0 ; space < rows-i ; space++)
        // {
        //     cout<<" ";
        // }

        cout<<endl;
    }
}
