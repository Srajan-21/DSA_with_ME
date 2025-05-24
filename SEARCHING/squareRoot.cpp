#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num=30;
    int prec=3;

    int start=0,end=num,ans;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid*mid==num)
        {
            ans=mid;
        }    
        if(mid*mid>num)    
        {
            end=mid-1;
        }
        else{
            ans = mid;
            start=mid+1;
        }
    } 
    cout<<"root="<<ans<<endl;

    

    double step=0.1;
    double final=ans;
    for(int i=0;i<prec;i++)
    {
        for(double j=final;j*j<=num;j=j+step)
        {
            final=j;
        }
        step/=10;
    }

    cout<<"answer="<<final;
    return 0;
}