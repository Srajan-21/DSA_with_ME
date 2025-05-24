#include <iostream>
using namespace std;
int checkKey(string str,int i,int n,char key)
{
    if(i>=n)
        return -1;

    if(str[i]==key)
         return i;

    return checkKey(str,i+1,n,key);
}
int main()
{
    string str="srajan";
    int n=str.length();
    char key='n';
    int i=0;

    cout<<"answer is:"<<checkKey(str,i,n,key);

}