#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> A{1,5,10,20,40,80};
    vector <int> B{6,7,20,80,100};
    vector <int> C{3,4,15,20,30,80,120};

    int n1=A.size();
    int n2=B.size();
    int n3=C.size();

    int i=0,j=0,k=0;
    vector <int> arr;

    while(i<n1 && j<n2 && k<n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            arr.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if(A[i]<B[j])
        {
            i++;
        }
        else if (B[j]<C[k])
        {
            j++;
        }
        else{
            k++;
        }
    }
    

    for(int m=0;m<arr.size();m++)
    {
        cout<<arr[m]<<" ";
    }
    
    return 0;
}

