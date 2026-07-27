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
    bool helper(TreeNode* root, int &targetsum, int sum) {
        if(root == nullptr) return false;

        sum+=root->val;
        if(root->left == nullptr && root->right == nullptr) {
            return sum == targetsum;
        }
        return (helper(root->left, targetsum, sum) || helper(root->right, targetsum, sum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if(root == nullptr) return false;
        return helper(root, targetSum, sum);
    }
};