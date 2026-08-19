class Solution {
public:
    vector<vector<int>> adj_list(int n , vector<vector<int>> &edges) {
        vector<vector<int>> list(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            list[u].push_back(v);
            list[v].push_back(u);
        }
        return list;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        if(n==2) return {0, 1};
        vector<vector<int>> list = adj_list(n, edges);
        queue<int> q;
        vector<int> visited(n);
        vector<int> degree(n);

        for(int i = 0; i<n; i++) {
            degree[i] = list[i].size();
        }
        for(int i=0; i<n; i++) {
            if(!visited[i] && degree[i] == 1) {
                q.push(i);
                visited[i] = 1;
            }
        }
        int remain = n;
        while (remain > 2) {
            int size = q.size();
            remain -= size;
            for (int i = 0; i < size; i++) {
                int leaf = q.front(); q.pop();
                for (int neighbour : list[leaf]) {
                    if (--degree[neighbour] == 1) {
                        q.push(neighbour);
                    }
                }
            }
        }
        vector<int> ans;
        int size = q.size();
        for(int i=0; i<size; i++) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};