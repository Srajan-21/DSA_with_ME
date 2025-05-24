#include <iostream>
#include <cstring>
using namespace std;

int swap(char &a,char &b)
{
    char t=a;
    a=b;
    b=t;
    return 0;
}

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

int reverse(char name[])
{
    int i=0;
    int n=getLength(name);
    int j=n-1;
    while(i<=j){
        swap(name[i],name[j]);
        i++;
        j--;
    }
    return 0;
}

int main(){
    char name[100];
    strcpy(name, "Srajan"); 
    cout << name << endl;
    reverse(name);
    cout << "Reversed String:"<<name;
    return 0;
}