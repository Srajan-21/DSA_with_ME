class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        for(int i = 0 ; i < n ; i++){
            arr.push_back({nums[i] , i});
        }

        sort(arr.begin() , arr.end());

        vector<int> position(n);
        vector<int> component(n);

        for(int i = 0 ; i < n ; i++){
            position[arr[i].second] = i;
        }

        int index = 0;
        component[0] = 0;
        for(int i = 1 ; i < n ; i++){
            if(arr[i].first - arr[i-1].first > maxDiff){
                index++;
            }
            component[i] = index;
        }

        vector<int> next(n);
        int r = 0;
        for(int l = 0 ; l < n ; l++){
            while (r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff) {
                r++;
            }
            next[l] = r;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG , vector<int>(n));
        for(int i = 0 ; i < n ; i++){
            up[0][i] = next[i];
        }

        for(int k = 1 ; k < LOG ; k++){
            for(int i = 0 ; i < n ; i++){
                up[k][i] = up[k-1][up[k-1][i]];
            }
        }

        vector<int>ans;

        for(auto& q : queries){
            int a = position[q[0]];
            int b = position[q[1]];

            if(a > b){
                swap(a , b);
            }

            if(component[a] != component[b]){
                ans.push_back(-1);
                continue;
            }

            if(a == b){
                ans.push_back(0);
                continue;
            }

            int curr = a;
            int jumps = 0;

            for(int k = LOG - 1 ; k >= 0 ; k--){
                if(up[k][curr] < b){
                    curr = up[k][curr];
                    jumps += (1 << k);
                }
            }

            ans.push_back(jumps+1);
        }

        return ans;
        
    }
};