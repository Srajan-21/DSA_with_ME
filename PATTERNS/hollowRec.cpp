    // *****
    // *   *
    // *****

    #include <iostream>
    using namespace std;

// my
    // int main(){
    //     for (int i = 0 ; i < 3 ; i++)
    //     {
    //         for(int j = 0 ; j < 5 ; j++)
    //         {
    //             if(i == 0 || i == 2){
    //                 cout<<"* ";
    //             }
    //             else
    //             {
    //                 if(j == 0 || j == 4){
    //                     cout<<"* ";
    //                 }
    //                 else
    //                 {
    //                     cout<<"  ";
    //                 }
    //             } 
    //         }
    //         cout<<endl;
    //     }
    // }

// babbar
// better bcoz less branches in inner loop avoids checking conditions inside inner loop
    int main(){

        int row,col;
        cout<<"enter row:";
        cin>>row;

        cout<<"enter collums:";
        cin>>col;

        int space = col-2;


        for (int i= 0 ;i < row ; i++)
        {
            if(i==0 || i == row-1){
            for(int j = 0 ; j < col ; j++)
            {
                cout<<"* ";
            }
            }
            else{
                cout<<"* ";
                for(int k = 0 ; k< space ;k++){
                    cout<<"  ";
                }
                cout<<"* ";
            }
            cout<<endl;
        }
        return 0;
    }

    // 

    
// #include <iostream>
// using namespace std;;

// int main(){
    
//     int rows;

//     cout<<"Enter rows:";
//     cin>>rows;

//     for (int i=0;i<rows;i++)
//     {
//         for(int j=0;j<rows;j++)
//         {
//             if(i==0 || i==rows-1 || j==0 || j==n-1)
//             {
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }    
// }

