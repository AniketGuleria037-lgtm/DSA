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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            long long start = q.front().second;
            long long end = q.back().second;
            ans = max(ans, end-start+1);

            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                long long norm_idx = idx-start;
                if(node->left) q.push({node->left, norm_idx*2+1});
                if(node->right) q.push({node->right, norm_idx*2+2});
                q.pop();
            }
        }
        return (int)ans;
    }
};