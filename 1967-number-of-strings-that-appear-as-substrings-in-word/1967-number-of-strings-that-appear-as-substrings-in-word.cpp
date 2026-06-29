class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count=0;
        
        for(auto s : patterns){
            size_t pos = word.find(s);

            if(pos != string::npos)
                count++;
        }

        return count;

    }
};