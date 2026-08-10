class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: enqueue all initially rotten oranges
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // 4 directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int time = 0;

        // Step 2: BFS level-order traversal
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for(int k=0; k<size; k++) {
                auto [row, col] = q.front();
                q.pop();

                for(int d=0; d<4; d++) {
                    int r_net = row + dr[d];
                    int c_net = col + dc[d];

                    if(r_net>=0 && r_net<r && c_net>=0 && c_net<c && grid[r_net][c_net] == 1) {
                        grid[r_net][c_net] = 2;
                        fresh--;
                        q.push({r_net, c_net});
                    }
                }
            }
            time++; // increment once per level
        }

        return fresh == 0 ? time : -1;
    }
};
