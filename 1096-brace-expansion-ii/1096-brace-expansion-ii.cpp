class Solution {

private:
    // expr_list = concat (',' concat)*
    set<string> parseExprList(const string& s, int& i) {
        set<string> result = parseConcat(s, i);
        while (i < (int)s.size() && s[i] == ',') {
            i++; // skip ','
            auto right = parseConcat(s, i);
            result.insert(right.begin(), right.end());
        }
        return result;
    }

    // concat = term term term ...
    set<string> parseConcat(const string& s, int& i) {
        set<string> result = {""};
        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            auto term = parseTerm(s, i);
            set<string> merged;
            for (auto& a : result)
                for (auto& b : term)
                    merged.insert(a + b);
            result = std::move(merged);
        }
        return result;
    }

    // term = letter | '{' expr_list '}'
    set<string> parseTerm(const string& s, int& i) {
        if (s[i] == '{') {
            i++; // skip '{'
            auto result = parseExprList(s, i);
            i++; // skip '}'
            return result;
        } else {
            return {string(1, s[i++])};
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto result = parseExprList(expression, i);
        return vector<string>(result.begin(), result.end()); 
    }
};