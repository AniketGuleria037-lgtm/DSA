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
    void helper(TreeNode* root, int &targetsum, int sum, vector<int> v, vector<vector<int>> &ans) {
        if(root == nullptr) return;
        sum+=root->val;
        v.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            if(sum == targetsum) ans.push_back(v);
        }
        helper(root->left, targetsum, sum, v, ans);
        helper(root->right, targetsum, sum, v, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(root, targetSum, 0, v, ans);
        return ans;
    }
};