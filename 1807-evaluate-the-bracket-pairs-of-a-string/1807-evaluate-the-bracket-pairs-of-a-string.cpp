class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result = "";
        string current_key = "";
        bool inside_bracket = false;
        
        // Step 2: Traverse the string s
        for (char c : s) {
            if (c == '(') {
                inside_bracket = true;
                current_key.clear();
            } else if (c == ')') {
                inside_bracket = false;
                // Check if the key exists in knowledge
                auto it = dict.find(current_key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } else {
                if (inside_bracket) {
                    current_key += c;
                } else {
                    result += c;
                }
            }
        }
        
        return result;
    }
};