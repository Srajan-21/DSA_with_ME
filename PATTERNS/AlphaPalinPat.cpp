//      A
//     ABA
//    ABCBA
//   ABCDCBA
//  ABCDEDCBA


#include <iostream>
using namespace std;

int main()
{    
    int rows;
    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0 ; i < rows ; i++ )    
    {
        for(int space = 0 ; space < rows - i ; space++)
        {
            cout<<" ";
        }

        for(int j = 0 ; j < i+1 ; j++)
        {
            int ans = j + 1;
            char ch = ans + 'A' - 1;
            cout<<ch;            
        }        

        for(int j = i ; j >= 1 ; j--)
        {
            int ans = j;
            char ch = ans + 'A' - 1;
            cout<<ch;
        }
        cout<<endl;
    }
}
