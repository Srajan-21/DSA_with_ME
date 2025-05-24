// 1
// 23
// 456
// 78910
// 1112131415



#include <iostream>
using namespace std;;

int main(){
    
    int rows;
    cout<<"Enter rows:";
    cin>>rows;

    int c=1;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cout<<c<<" ";
            c++;
        }
        cout<<endl;
    }    
}