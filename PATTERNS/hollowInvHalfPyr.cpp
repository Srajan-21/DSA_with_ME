// ******
// *   *
// *  *
// * *
// **
// *



#include <iostream>
using namespace std;;

int main(){
    
    int rows;

    cout<<"Enter rows:";
    cin>>rows;


    for(int i = 0 ; i < rows ; i++)
    {
        int j;
        
            for( j = 0 ; j < rows-i ; j++)
            {
                if(i==0 || j == 0 || j == rows-i-1){
                    cout<<"*";
                }
                else
                    {
                        cout<<" ";
                    }
          
        }
        cout<<endl;
    }    
}






// #include <iostream>
// using namespace std;;

// int main(){
    
//     int rows;

//     cout<<"Enter rows:";
//     cin>>rows;


//     for(int i = 0 ; i < rows ; i++)
//     {
//         int j;
        
//             for( j = 0 ; j < rows; j++)
//             {
//                 if(i==0 || j == 0 || j == rows-i-1)
//                     {
//                         cout<<"*";
//                     }
//                 else 
//                     {
//                         cout<<" ";
//                     }
//             }
//         }
//         cout<<endl;
//     }    
