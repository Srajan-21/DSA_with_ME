#include <iostream>
using namespace std;

void printPermutation(string &s , int i)
{
    if(i>=s.length())
    {
        cout<<s<<" ";
        return ;
    }

    // swapping
    for(int j=i;j<s.length();j++)
    {
        // swap
        swap(s[i],s[j]);
        // recursive call
        printPermutation(s,i+1);
        // backtracking
        swap(s[i],s[j]);
    }

}
int main(){
    string s = "abc";
    int i=0;
    printPermutation(s,i);
    return 0;    
}