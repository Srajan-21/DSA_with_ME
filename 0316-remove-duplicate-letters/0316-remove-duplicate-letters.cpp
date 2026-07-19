class Solution {
public:
    string removeDuplicateLetters(string s) {
        
         unordered_map<char, int> last;

        for (int i = 0; i < s.size(); i++)
            last[s[i]] = i;

        stack<char> st;
        unordered_set<char> visited;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (visited.count(ch))
                continue;

            while (!st.empty() &&
                   st.top() > ch &&
                   last[st.top()] > i) {

                visited.erase(st.top());
                st.pop();
            }

            st.push(ch);
            visited.insert(ch);
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};