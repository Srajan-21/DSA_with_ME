class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin() , intervals.end() , 
            []( vector<int>& a , vector<int>& b ){
                if(a[0] == b[0]){
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            }
        );

        int count = 0;
        int maxEnd = INT_MIN;

        for(auto i : intervals){
            int end = i[1];
            if(end > maxEnd)
                maxEnd = end;
            else 
                count++;
        }
        return intervals.size() - count;
    }
};