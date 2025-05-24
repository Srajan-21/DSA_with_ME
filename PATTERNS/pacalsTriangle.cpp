//       1
//      1 1
//     1 2 1
//    1 3 3 1
//   1 4 6 4 1
// 1 5 10 10 5 1



#include <iostream>
using namespace std;

int main(){

    int rows;
    cin>>rows;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows-i-1;j++)
        {
            cout<<" ";
        }

        int num=1;
        for(int j=0;j<=i;j++)
        {
            cout<<num<<" ";
            num=num*(i-j)/(j+1);
        }
        cout<<endl;
    }
}
