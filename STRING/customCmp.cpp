#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

bool cmp(char first ,char second)
{
    return first > second;
}
int main()
{
    string s="srajan";
    sort(s.begin(),s.end(),cmp);
    cout<<s<<endl;
    return 0;

}