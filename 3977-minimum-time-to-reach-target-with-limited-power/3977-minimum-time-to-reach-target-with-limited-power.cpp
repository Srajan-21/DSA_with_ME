class Solution {
public:

    using ll = long long;
    const ll INF = 4e18;
    
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {

        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<ll>> dist(n, vector<ll>(power + 1, INF));

        using State = tuple<ll, int, int>; 
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while (!pq.empty()) {
            auto [time, u, rem] = pq.top();
            pq.pop();

            if (time != dist[u][rem]) continue;

            if (rem < cost[u]) continue;

            int nextPower = rem - cost[u];

            for (auto &[v, w] : graph[u]) {
                ll newTime = time + (ll)w;
                if (newTime < dist[v][nextPower]) {
                    dist[v][nextPower] = newTime;
                    pq.push({newTime, v, nextPower});
                }
            }
        }

        ll bestTime = INF;
        ll bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] == INF) continue;

            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            } else if (dist[target][p] == bestTime) {
                bestPower = max(bestPower, (ll)p);
            }
        }

        if (bestTime == INF) return {-1, -1};

        return {bestTime, bestPower};
   
        
    }
};