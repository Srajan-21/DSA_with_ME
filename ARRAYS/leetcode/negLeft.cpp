#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> arr{1,2,-3,4,-5,6};

    int l=0,h=arr.size()-1;

    while(l<h)
    {
        if(arr[l]<0) //negative h to aage bada do l ko
        {
            l++;
        }
        else if(arr[h]>0)  //positive h to peeche le aao h ko
        {
            h--;
        }
        else{
            swap(arr[l],arr[h]);
        }
    }

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

// worst case me jab saare negative honge to l ko har baar increase hoke right me move krna hoga to nitne no honge arr me utni baar loop chalega 
// Time complexity = O(n)
// Space complexity = O(1) no extra space