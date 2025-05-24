#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s,string t)
{
     //O(m+n)
     int freqTable[256]={0};

     for(int i=0;i<s.size();i++)
     {
         freqTable[s[i]]++;
     } //O(m)

     for(int i=0;i<t.size();i++)
     {
         freqTable[t[i]]--;
     } //O(n)

     for(int i=0;i<256;i++)
        {
            if(freqTable[i]!=0)
            {
                return false;
            }
        }

        return true; 
}

int main(){
    string s="rat";
    string t="car";

    cout<<isAnagram(s,t);
    return 0;
}