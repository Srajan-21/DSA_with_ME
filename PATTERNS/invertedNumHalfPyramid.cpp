// 12345
// 1234
// 123
// 12
// 1

#include <iostream>
using namespace std;;

int main(){
    
    int rows;

    cout<<"Enter rows:";
    cin>>rows;

    for(int i = 0; i < rows; i++){
        for(int j = 0 ; j < rows-i ; j++)
        {
            cout<<j+1;
        }
        cout<<endl;
    }
}
