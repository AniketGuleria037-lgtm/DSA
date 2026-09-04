class Solution {
public:
    int mod(int a, int b) {
        if(a > b) return a-b;
        else return b-a;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                effort[i][j] = INT_MAX;
            }
        }
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int e = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for(int i=0; i<4; i++) {
                int r_net = r + dr[i];
                int c_net = c + dc[i];

                if(r_net >= 0 && r_net < m && c_net >= 0 && c_net < n) {
                    int newEffort = max(e, mod(heights[r][c], heights[r_net][c_net]));
                    if(newEffort < effort[r_net][c_net]) {
                        effort[r_net][c_net] = newEffort;
                        pq.push({newEffort, {r_net, c_net}});
                    }
                }
            }
        }
        return effort[m-1][n-1];
    }
};