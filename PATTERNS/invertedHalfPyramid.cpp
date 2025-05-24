// *****
// ****
// ***
// **
// *

// O(rows^2)
 


#include <iostream>
using namespace std;

// better my
int main(){
    int rows;

    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0; i< rows; i++){
        for(int j = rows ; j > i ; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

// babbar
// int main(){
//     int rows;
//     cout<<"Enter rows:";
//     cin>>rows;

//     for(int i = 0; i< rows; i++){
//         for(int j = 0 ; j < rows-i ; j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }

// }