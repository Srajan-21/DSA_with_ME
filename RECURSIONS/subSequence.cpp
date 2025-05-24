#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(string str,string ans,int i,vector<string>&v)
{
    if(i>=str.length())
    {
        v.push_back(ans);
        return ;
    }

    // exclude
    printSubsequence(str,ans,i+1,v);

    // include
    ans.push_back(str[i]);
    printSubsequence(str,ans,i+1,v);
}
int main()
{
    string str="abcd";
    string output="";
    vector<string> v;
    int i=0;
    printSubsequence(str,output,i,v);
 
    for(auto val:v)
    {
        cout<<val<<"_"<<endl;
    }
    cout<<"Number of Subsequences:"<<v.size();
    return 0;
}