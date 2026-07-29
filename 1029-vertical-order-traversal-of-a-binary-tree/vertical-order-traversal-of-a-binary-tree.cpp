/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> m;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            m[x][y].insert(node->val);

            if(node->left != nullptr) q.push({node->left, {x-1, y+1}});
            if(node->right != nullptr) q.push({node->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto it1 : m) {
            vector<int> v;
            for(auto it2 : it1.second) {
                v.insert(v.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};