class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> v(row, vector<int>(col));
        queue<pair<int, int>> q;

        int initial = image[sr][sc];

        q.push({sr, sc});
        v[sr][sc] = 1;
        image[sr][sc] = color;

        while(!q.empty()) {
            auto p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();

            for(int delrow=-1; delrow<=1; delrow++) {
                int r_net  = r+delrow;
                if(r_net >= 0 && r_net < row && !v[r_net][c] && image[r_net][c] == initial) {
                    q.push({r_net, c});
                    v[r_net][c] = 1;
                    image[r_net][c] = color;
                }
            }
            for(int delcol=-1; delcol<=1; delcol++) {
                int c_net  = c+delcol;
                if(c_net >= 0 && c_net < col && !v[r][c_net] && image[r][c_net] == initial) {
                    q.push({r, c_net});
                    v[r][c_net] = 1;
                    image[r][c_net] = color;
                }
            }
        }
        return image;
    }
};