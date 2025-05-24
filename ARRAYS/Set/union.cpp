#include <iostream>
#include <vector>
using namespace std;

bool isPresent(vector<int> &result , int element)
{
    for(int i=0;i<result.size();i++)
    {
        if(result[i] == element)
        return true;
    }
    return false;
}

vector<int> findUnion(int arr[],int brr[],int sizea,int sizeb)
{

    vector<int> unionResult;
    for(int i=0;i<sizea;i++)
    {
        if(!isPresent(unionResult,arr[i]))
        {
            unionResult.push_back(arr[i]);
        }
    }

    for(int i=0;i<sizeb;i++)
    {
        if(!isPresent(unionResult,brr[i]))
        {
            unionResult.push_back(brr[i]);
        }
    }

    return unionResult;

}

// no duplicates
int main()
{
    int a[]={1,2,5,6,4,4,9};
    int b[]={5,6,9,8};
    int sizea= sizeof(a)/sizeof(int);
    int sizeb= sizeof(b)/sizeof(int);

    vector <int> ans = findUnion(a,b,sizea,sizeb);

    cout<<"Union of Two Arrays:";
    for(int i:ans){
        cout<<i<<" ";
    }
    
    return 0;

}

