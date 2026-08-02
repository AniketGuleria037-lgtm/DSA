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
    bool helper(TreeNode* root, long long lb, long long ub) {
        if(root == NULL) return true;
        if(root->val >=ub || root->val <= lb) return false;
        if(!helper(root->left, lb, root->val)) return false;
        if(!helper(root->right, root->val, ub)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return (helper(root, LLONG_MIN, LLONG_MAX));
    }
};