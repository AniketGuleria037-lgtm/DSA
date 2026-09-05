class Solution {
public:
    vector<vector<pair<int, int>>> adj_list(vector<vector<int>>& flights, int n) {
        vector<vector<pair<int, int>>> list(n);
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            list[u].push_back({v, w});
        }
        return list;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> list = adj_list(flights, n);
        vector<int> dist(n);
        for(int i=0; i<n; i++) {
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while(!q.empty()) {
            auto j = q.front();
            int s = j.first;
            int u = j.second.first;
            int d = j.second.second;
            q.pop();
            if(s > k) continue;
            for(auto it : list[u]) {
                int v = it.first;
                int w = it.second;
                if(d + w < dist[v] && s <= k) {
                    dist[v] = d + w;
                    q.push({s+1, {v, dist[v]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};