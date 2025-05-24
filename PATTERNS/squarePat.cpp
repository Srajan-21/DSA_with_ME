// patterns use nested loops

// *****
// *****
// *****

#include <iostream>
using namespace std;

int main() {

    // outer loop is for rows
    for (int i = 0 ; i < 3 ; i++)
    {
        // inner loop is for collumns
        for (int j = 0 ; j < 5 ; j++)
        {
            // printing content
            cout<<"*";
        }
        // changing line
        cout<<endl;
    }
    return 0;
}
