#include <iostream>
#include <cstring>
using namespace std;


int getLength(char name[])
{
    int length=0;
    int i=0;
    while(name[i]!='\0')
    {
       length++;
       i++;
    }
    return length;
}

int main(){
    char name[100];
    strcpy(name, "Srajan"); 
    cout << name << endl;
    cout << "Length:"<<getLength(name);
    return 0;
}