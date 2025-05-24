#include <iostream>
#include <string>
using namespace std;


bool chkPalindrome(string &s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string &s)
{
    int i=0;
    int j=s.length()-1;

    while(i<=j){
        if(s[i]!=s[j])
        {
            return chkPalindrome(s,i+1,j)||chkPalindrome(s,i,j-1);
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s="leverl";
    
    if(validPalindrome(s))
        cout<<"true";
    else
        cout<<"false";
    
    return 0;
}