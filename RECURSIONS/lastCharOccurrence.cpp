#include  <iostream>
using namespace std;

void lastOccLtR(string s, char ch, int i,int & ans)
{
    // base case
    if(i>=s.size())
    {
        return;
    }

    if(s[i]==ch)
    ans=i;

    lastOccLtR(s,ch,i+1,ans);
}

void lastOccRtL(string s, char ch, int i,int & ans)
{
    // base case
    if(i==0)
    {
        return;
    }

    if(s[i]==ch)
    {ans=i;
        return;}

    lastOccLtR(s,ch,i-1,ans);
}
int main(){
    string s="ahdkhyhkbfhks";
    char ch='k',c='s';
    int ans=-1;
    int k=-1;
    int i=0;
    int j=s.length();
    lastOccLtR(s,ch,i,ans);
    lastOccRtL(s,c,j,k);
    cout<<ans<<endl;
    cout<<k;
}
