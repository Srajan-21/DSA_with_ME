#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[100];
    strcpy(word, "SraJan"); 
    cout << word << endl;

    for(int i=0;i<strlen(word);i++)
    {
        if(word[i]>'A' && word[i]<'Z')
        {
            word[i]=word[i]-'A'+'a';
        }
    }

    cout << word <<endl;
    return 0;
}