class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(row, vector<int>(col, -1));

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int d=0; d<4; d++) {
                int r_net = r + dr[d];
                int c_net = c + dc[d];

                if(r_net>=0 && r_net<row && c_net>=0 && c_net<col && ans[r_net][c_net] == -1) {
                    ans[r_net][c_net] = ans[r][c] + 1;
                    q.push({r_net, c_net});
                }
            }
        }
        return ans;

    }
};