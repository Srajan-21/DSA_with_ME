class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };
    
    int K, n;
    vector<Node> tree;
    
    Node merge(const Node& a, const Node& b) {
        Node res;
        res.prod = (a.prod * b.prod) % K;
        for (int v = 0; v < K; v++)
            res.cnt[v] = a.cnt[v];
        for (int u = 0; u < K; u++)
            if (b.cnt[u])
                res.cnt[(a.prod * u) % K] += b.cnt[u];
        return res;
    }
    
    void build(vector<int>& nums, int nd, int s, int e) {
        if (s == e) {
            tree[nd].prod = nums[s] % K;
            memset(tree[nd].cnt, 0, sizeof(tree[nd].cnt));
            tree[nd].cnt[nums[s] % K] = 1;
            return;
        }
        int mid = (s + e) / 2;
        build(nums, 2*nd, s, mid);
        build(nums, 2*nd+1, mid+1, e);
        tree[nd] = merge(tree[2*nd], tree[2*nd+1]);
    }
    
    void update(int nd, int s, int e, int idx, int val) {
        if (s == e) {
            tree[nd].prod = val % K;
            memset(tree[nd].cnt, 0, sizeof(tree[nd].cnt));
            tree[nd].cnt[val % K] = 1;
            return;
        }
        int mid = (s + e) / 2;
        if (idx <= mid) update(2*nd, s, mid, idx, val);
        else update(2*nd+1, mid+1, e, idx, val);
        tree[nd] = merge(tree[2*nd], tree[2*nd+1]);
    }
    
    Node query(int nd, int s, int e, int l, int r) {
        if (r < s || e < l) return Node(); // identity: prod=1, cnt all 0
        if (l <= s && e <= r) return tree[nd];
        int mid = (s + e) / 2;
        return merge(query(2*nd, s, mid, l, r), query(2*nd+1, mid+1, e, l, r));
    }
    
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n-1);
        
        vector<int> result;
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            nums[idx] = val;
            update(1, 0, n-1, idx, val);
            Node res = query(1, 0, n-1, start, n-1);
            result.push_back(res.cnt[x]);
        }
        return result;
    }
};