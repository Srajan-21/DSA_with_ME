class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '#';
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.pref = a.pref;

        if (a.pref == a.len && a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if (b.suff == b.len && a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        // Best
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {

        if (l == r) {
            seg[node].leftChar = ch;
            seg[node].rightChar = ch;
            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, ch);
        else
            update(node * 2 + 1, mid + 1, r, idx, ch);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};