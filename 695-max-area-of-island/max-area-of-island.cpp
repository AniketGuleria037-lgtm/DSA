class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &v, vector<vector<int>> &grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        v[i][j] = 1;
        q.push({i, j});
        int ans = 1;

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int delrow = -1; delrow<=1; delrow++) {
                int r_net = row + delrow;
                if(r_net>=0 && r_net < r && grid[r_net][col] == 1 && !v[r_net][col]) {
                    ans++;
                    q.push({r_net, col});
                    v[r_net][col] = 1;
                }
            }
            for(int delcol = -1; delcol<=1; delcol++) {
                int c_net = col + delcol;
                if(c_net>=0 && c_net < c && grid[row][c_net] == 1 && !v[row][c_net]) {
                    ans++;
                    q.push({row, c_net});
                    v[row][c_net] = 1;
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r =grid.size();
        int c = grid[0].size();
        int max_area = 0;

        vector<vector<int>> visited(r, vector<int>(c));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    int area = bfs(i, j, visited, grid);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};