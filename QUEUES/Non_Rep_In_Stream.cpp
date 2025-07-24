#include <iostream>
#include<queue>
using namespace std;

// TC SC => o(n)
int main(){
    string str = "aacdabc";
    int freq[26]={0};
    queue<char>q;

    string ans = "";

    for(int i = 0; i<str.length() ; i++){
        char ch = str[i];

        // increase frequency
        freq[ch-'a']++;

        q.push(ch);
 
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1){
                q.pop();
                cout<<"ans : "<<ans<<endl;
            }
            else{
                ans.push_back(q.front());
                cout<<ans<<endl;
                break; 
            }
        }

        if(q.empty()){
            ans.push_back('#');
            cout<<"op : "<<ans<<endl;
        }
    }

    cout<<ans;
}