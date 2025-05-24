#include <iostream>
using namespace std;

int main(){
    int dividend=22;
    int divisor=0;

    int start=0;
    int end=abs(dividend);
    int ans;

    if(dividend==0)
    {
        ans=0;
        cout<<"answer="<<ans;
        return 0;
    }
    if(divisor==0)
    {
        cout<<"answer=not difined";
        return 0;
    }

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(abs(mid*divisor)==abs(dividend)){
        ans=mid;
        break;
        }
        else if(abs(mid*divisor)<abs(dividend))
        {
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }         
    }

    if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
    cout<<"anwser="<<ans;
    else
    cout<<"answer="<<-ans;
    return 0;
}