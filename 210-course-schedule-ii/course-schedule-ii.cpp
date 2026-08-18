class Solution {
public:
    vector<vector<int>> adj_list(int n, vector<vector<int>> &prereq) {
        vector<vector<int>> adj(n);
        for(auto it : prereq) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        
        return adj;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = adj_list(numCourses, prerequisites);
        vector<int> indegree(numCourses);
        queue<int> q;
        vector<int> topo;
        for(auto it : prerequisites) {
            indegree[it[0]]++;
        }
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            topo.push_back(n);

            for(auto it : adj[n]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() != numCourses) topo.clear();
        return topo;
    }
};