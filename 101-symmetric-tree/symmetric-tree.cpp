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
    bool isMirrorImage(TreeNode* r1, TreeNode* r2) {
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 == nullptr || r2 == nullptr) return false;

        return(r1->val == r2->val && isMirrorImage(r1->left, r2->right) && isMirrorImage(r1->right, r2->left));
    }
    bool isSymmetric(TreeNode* root) {
        return(isMirrorImage(root->left, root->right));
    }
};