#include <iostream>
#include<vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int> >& m , int n){
    stack<int> st;

    // push all persons into stack
    for(int i = 0;i<n;++i){
        st.push(i);
    }

    // run discard mthd to get mightBeCelebriity
    while(st.size()!=1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a knows b
        if(m[a][b]){
            // a is not celebrity b might be
            st.push(b);
        }
        else{
            // b is not celebrity a might be
            st.push(a);
        }
    }

    // check that single person is actually celebrity or not
    int mightBeCelebrity = st.top();
    st.pop();

    // celebrity should not know anyone
    for(int i=0;i<n;i++){
        if(m[mightBeCelebrity][i]!=0){
            return -1;
        }
    }

    // everyone should know celebrity
    for(int  i = 0 ; i<n ; i++){
        if(m[i][mightBeCelebrity]==0 && i!=mightBeCelebrity)
        return -1;
    }

    return mightBeCelebrity;
}

int main(){
    vector<vector<int> > arr = {{0,1,0},
                                {0,0,0},
                                {0,1,0}};

    cout<<celebrity(arr , 3);
    return 0;
}