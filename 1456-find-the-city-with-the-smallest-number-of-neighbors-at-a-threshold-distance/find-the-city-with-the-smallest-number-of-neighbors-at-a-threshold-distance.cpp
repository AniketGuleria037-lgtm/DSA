class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = INT_MAX;
            }
        }
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int k=0; k<n; k++) {
            for(int j=0; j<n; j++) {
                for(int i=0; i<n; i++) {
                    if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int min_count = INT_MAX;
        int ans = 0;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(dist[i][j] <= distanceThreshold) count++;
            }
            if(min_count >= count) {
                min_count = count;
                ans = i;
            }
        }
        return ans;
    }
};