//    *
//   ***
//  *****
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

        // for(int j = 0 ; j < ((2*i)+1) ; j++)
        for(int j = 0 ; j < i+1 ; j++)
        {
            cout<<"* ";
        }       
        
        // for(int space = 0 ; space < rows-i ; space++)
        // {
        //     cout<<" ";
        // }

        cout<<endl;
    }
}



// babbar
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int k=0;
//         for(int j=0;j<(2*n)-1;j++){
//             if(j<n-i-1){
//                 cout<<" ";
//             }
//             else if(k<2*i+1){
//                 cout<<"*";
//                 k++;
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }