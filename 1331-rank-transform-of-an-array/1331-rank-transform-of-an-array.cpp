class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> v2(arr);
        sort(v2.begin() , v2.end());

        unordered_map<int , int> rank;
        int currRank = 1;

        for(int i = 0 ; i < v2.size() ; i++){
            if(rank.count(v2[i]) == 0){
                rank[v2[i]] = currRank++;
            }
        } 

        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};