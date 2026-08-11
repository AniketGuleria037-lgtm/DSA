class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &v, vector<vector<int>> &safe, vector<vector<char>> &m) {
        int row = m.size();
        int col = m[0].size();
        v[i][j] = 1;
        safe[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int d=0; d<4; d++) {
                int r_net = r + dr[d];
                int c_net = c + dc[d];
                if(r_net >= 0 && r_net < row && c_net >=0 && c_net < col && m[r_net][c_net] == 'O' && !v[r_net][c_net]) {
                    safe[r_net][c_net] = 1;
                    v[r_net][c_net] = 1;
                    q.push({r_net, c_net});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       int row = board.size();
       int col = board[0].size();
       vector<vector<int>> visited(row, vector<int>(col));
       vector<vector<int>> safe(row, vector<int>(col));

       for(int i=0; i<row; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) bfs(i, 0, visited, safe, board);

            if(board[i][col-1] == 'O' && !visited[i][col-1]) bfs(i, col-1, visited, safe, board);
        }
        for(int i=0; i<col; i++) {
            if(board[0][i] == 'O' && !visited[0][i]) bfs(0, i, visited, safe, board);
            
            if(board[row-1][i] == 'O' && !visited[row-1][i]) bfs(row-1, i, visited, safe, board);
        }
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == 'O' && !safe[i][j]) board[i][j] = 'X';
            }
        }
    }
};