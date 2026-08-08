class Solution {
public:
    void bfs(int start, vector<int> &v, vector<vector<int>> &adj) {
        v[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            for(int i=0; i<v.size(); i++) {
                if(adj[n][i] == 1 && !v[i]) {
                    q.push(i);
                    v[i] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int> visited(n);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                provinces++;
                bfs(i, visited, isConnected);
            }
        }
        return provinces;
    }
};