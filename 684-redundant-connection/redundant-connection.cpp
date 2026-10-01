class Solution {
public:
void Union(int a, int b, vector<int> &p, vector<int> &s) {
    int c = find_set(p, a);
    int d = find_set(p, b);
    if(s[c] > s[d]) p[d] = c;
    else p[c] = d;
    if(s[c] == s[d]) s[d]++;
}

int find_set(vector<int> &parent, int a) {
    if(parent[a] == a) return a;
    return parent[a] = find_set(parent, parent[a]);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> Size(n+1);
        vector<int> ans(2);

        for(int j = n-1; j>=0; j--) {
            for(int i=0; i<=n; i++) {
                parent[i] = i;
                Size[i] = 1;
            }
            for(int i=0; i<n; i++) {
                if(i == j) continue;
                Union(edges[i][0], edges[i][1], parent, Size);
            }
            int c = 1;
            int u = 0;
            for(int i = 1; i<=n; i++) {
                if(u == 0) u = find_set(parent, i);
                else {
                    if(find_set(parent, i) != u) c++;
                }
            }
            if(c == 1) return ans = edges[j];
        }
        return ans;
    }
};