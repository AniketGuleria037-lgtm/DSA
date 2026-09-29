class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        visited[0][0] = 1;
        
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        
        int t = 0;
        while(!pq.empty()) {
            auto [elev, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            t = max(elev, t);
            if(r == n-1 && c == n-1) return t;

            for(int k = 0; k<4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc], {nr,nc}});
                }
            }

        }
        return -1;
    }
};