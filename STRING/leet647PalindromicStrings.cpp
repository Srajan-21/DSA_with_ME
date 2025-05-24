#include <iostream>
#include <string>

using namespace std;

int expandAroundIndex(string s,int i,int j)
{
    int count=0;

    while(i>=0 && j<s.length() && s[i]==s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstring(string s)
{
    int totalCount=0;

    for(int i=0;i<s.length();i++)
    {
        // for odd substrings
        int odd=expandAroundIndex(s,i,i);
        totalCount+=odd;
        int even=expandAroundIndex(s,i,i+1);
        totalCount+=even;
    }
    return totalCount;
}

int main()
{
    cout<<countSubstring("noon");
    return 0;
}