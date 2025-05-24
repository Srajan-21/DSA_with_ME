//     1
//    232
//   34543
//  4567654
// 567898765


#include <iostream>
using namespace std;;

int main()
{    
    int rows;
    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0 ; i < rows ; i++ )    
    {
        int num=i+1;
        for(int space = 0 ; space < rows - i ; space++)
        {
            cout<<" ";
        }

        for(int j = 0 ; j < i+1 ; j++)
        {
            cout<<num;
            num++;
        }

        num=num-2;

        for(int j = i ; j >= 1 ; j--)
        {
            cout<<num;
            num--;
        }
        cout<<endl;
    }
}
