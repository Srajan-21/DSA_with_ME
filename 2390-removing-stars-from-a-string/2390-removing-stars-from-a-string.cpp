class Solution {
public:
    string removeStars(string s) {

        string res;
        for(auto& ch : s){
            if(ch!='*')
                res.push_back(ch);
            else
                res.pop_back();
        }
        
        // stack<char>st;
        // for(auto& ch : s){
        //     if(ch != '*')st.push(ch);
        //     else st.pop();
        // }

        // string res = "";
        // while(!st.empty()){
        //     res = st.top() + res;
        //     st.pop();
        // }

        return res;
    }
};