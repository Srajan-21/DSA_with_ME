class Solution {
public:
    string smallestSubsequence(string s) {
        
        unordered_map<char , int> last;
        for(int i = 0 ; i < s.length() ; i++)
        {
            last[s[i]] = i;
        }

        stack<char> st;
        unordered_set<char> visited;

        for(int i = 0 ; i < s.length() ; i++)
        {
            char ch = s[i];

            if(visited.count(ch))
                continue;

            while(!st.empty() && st.top() > ch && last[st.top()] > i)
            {
                visited.erase(st.top());
                st.pop();
            }
            
            st.push(ch);
            visited.insert(ch);
        }

        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};