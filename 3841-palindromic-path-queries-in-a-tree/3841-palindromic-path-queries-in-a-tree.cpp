class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = max(1, __lg(max(n, 2)) + 1);
        vector<int> tin(n), tout(n), dep(n), pref(n);
        vector<vector<int>> up(n, vector<int>(LOG, -1));

        // Iterative DFS for Euler tour, depth, parent, prefix XOR
        int timer = 0;
        struct Frame { int nd, par; bool leaving; };
        vector<Frame> stk;
        stk.push_back({0, -1, false});
        while (!stk.empty()) {
            auto [nd, par, leaving] = stk.back();
            stk.pop_back();
            if (leaving) { tout[nd] = timer - 1; continue; }
            tin[nd] = timer++;
            up[nd][0] = par;
            dep[nd] = (par < 0) ? 0 : dep[par] + 1;
            pref[nd] = 1 << (s[nd] - 'a');
            if (par >= 0) pref[nd] ^= pref[par];
            stk.push_back({nd, par, true});
            for (int v : adj[nd])
                if (v != par) stk.push_back({v, nd, false});
        }

        // Binary lifting table
        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                if (up[v][k-1] >= 0) up[v][k] = up[up[v][k-1]][k-1];

        // LCA function
        auto lca = [&](int a, int b) -> int {
            if (dep[a] < dep[b]) swap(a, b);
            int d = dep[a] - dep[b];
            for (int k = 0; k < LOG; k++)
                if ((d >> k) & 1) a = up[a][k];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; k--)
                if (up[a][k] != up[b][k]) { a = up[a][k]; b = up[b][k]; }
            return up[a][0];
        };

        // BIT for range XOR update / point query
        vector<int> bit(n + 2, 0);
        auto bupd = [&](int i, int v) {
            for (i++; i <= n; i += i & -i) bit[i] ^= v;
        };
        auto bqry = [&](int i) -> int {
            int r = 0;
            for (i++; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };

        // Process queries
        vector<bool> ans;
        for (auto& q : queries) {
            istringstream iss(q);
            string type; iss >> type;
            if (type == "update") {
                int u; char c;
                iss >> u >> c;
                if (s[u] != c) {
                    int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                    bupd(tin[u], d);
                    if (tout[u] + 1 < n) bupd(tout[u] + 1, d);
                    s[u] = c;
                }
            } else { // "query"
                int u, v;
                iss >> u >> v;
                int l = lca(u, v);
                int x = pref[u] ^ bqry(tin[u]) ^ pref[v] ^ bqry(tin[v]) 
                       ^ (1 << (s[l] - 'a'));
                ans.push_back(x == 0 || (x & (x - 1)) == 0);
            }
        }
        return ans;
    }
};