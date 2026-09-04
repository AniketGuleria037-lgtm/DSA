class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = INT_MAX;
            }
        }
        dist[0][0] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});

        while(!q.empty()) {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    int r_net = r+i;
                    int c_net = c+j;

                    if(r_net < n && r_net >= 0 && c_net < n && c_net >= 0 && grid[r_net][c_net] == 0 && d+1 < dist[r_net][c_net]) {
                        dist[r_net][c_net] = d+1;
                        q.push({d+1, {r_net, c_net}});
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1] + 1;
    }
};