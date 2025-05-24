#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[100];
    strcpy(word, "Noon"); 
    cout << word << endl;

    for(int i=0;i<strlen(word);i++)
    {
        if(word[i]>'a' && word[i]<'z')
        {
            word[i]=word[i]-'a'+'A';
        }
    }

    cout << word <<endl;
    return 0;
}