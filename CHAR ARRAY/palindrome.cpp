#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char word[])
{
    int i=0;
    int n=strlen(word);
    int j=n-1;

    while(i<=j)
    {
        if(word[i]!=word[j])
            return false;
        
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    char word[100];
    strcpy(word, "noon"); 
    cout << word << endl;
    if(checkPalindrome(word))
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
   
    return 0;
}