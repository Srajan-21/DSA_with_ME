#include <iostream>
#include <cstring>
using namespace std;

void replaceSpace(char sentence[])
{
    int n=strlen(sentence);
    for(int i=0;i<n;i++)
    {
        if(sentence[i]==' ')
        {
            sentence[i]='@';
        }
    }
}

int main(){
    char sentence[100];
    strcpy(sentence, "My name is Srajan Srivastava"); 
    cout << sentence << endl;
    replaceSpace(sentence);
    cout << "Reversed String:"<<sentence;
    return 0;
}