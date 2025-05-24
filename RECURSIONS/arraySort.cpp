#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> v,int n,int i)
{
    if(i==n-1)
        return true;

    if(v[i+1]<v[i])
    {
        return false;
    }

    return checkSorted(v,n,i+1);
}

int main(){
    vector <int>v{10,20,30,40,60,50};
    int n=v.size();
    int i=0;

    bool isSorted = checkSorted(v,n,i);
    if(isSorted)
        cout<<"Sorted";
    else
        cout<<"Not Sorted";

    return 0;

}