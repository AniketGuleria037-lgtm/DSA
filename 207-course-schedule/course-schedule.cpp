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
    vector<int> find_indegree(int n, vector<vector<int>> &adj) {
        vector<int> indegree(n);
        for(auto it1 : adj) {
            for(auto it2 : it1) {
                indegree[it2]++;
            }
        }
        return indegree;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = adj_list(numCourses, prerequisites);
        vector<int> indegree = find_indegree(numCourses, adj);

        vector<int> ans;
        queue<int> q;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);

            for(auto it : adj[n]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
            
        }
        return (ans.size() == numCourses);
    }
};