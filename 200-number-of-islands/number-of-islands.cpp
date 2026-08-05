class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &v) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        v[row][col] = 1;
        q.push({row, col});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int delrow = -1; delrow<=1; delrow++) {
                int nrow = r + delrow;
                if(nrow>=0 && nrow < n && grid[nrow][c] == '1' && v[nrow][c] == 0) {
                    q.push({nrow, c});
                    v[nrow][c] = 1;
                }
            }
            for(int delcol = -1; delcol<=1; delcol++) {
                int ncol = c + delcol;
                if(ncol >=0 && ncol < m && grid[r][ncol] == '1' && v[r][ncol] == 0) {
                    q.push({r, ncol});
                    v[r][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> v(r, vector<int>(c, 0));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == '1' && v[i][j] == 0) {
                    bfs(i, j, grid, v);
                    count++;
                }
            }
        }
        return count;
    }
};