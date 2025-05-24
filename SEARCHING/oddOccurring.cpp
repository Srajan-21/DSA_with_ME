#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr{1,1,2,2,3,4,4,5,5,6,6};
    int start=0,end=arr.size()-1;
int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;

        // single element
        if(start==end)
        {
            ans= start;
            break;
        }

        // 2 cases
        // mid=even
        if(mid%2==0)
        {
            if(arr[mid]==arr[mid+1])
            {
                // right me ans hoga
                start=mid+2;
            }
            else
            {
                // mid can be the ans or ans will be at left of the mid
                end=mid;
            }
        }
        else
        {
            if(arr[mid]==arr[mid-1])
            {
                // same as case 1 if condition
                // right me ans hoga
                start=mid+1;
            }
            else
            {
                // left me hhoga ans mid pe nhi ho skta kyuki ans odd posiyion pe kbhi nhi hoga
                // ans left me hoga mid k
                end=mid-1;
            }
        }
    }

    
    cout<<"index="<<ans;
    return 0;
} 