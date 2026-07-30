/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool root_to_leaf_path(TreeNode* root, TreeNode* x, vector<TreeNode*> &ans) {
        if(root == nullptr) return false;
        ans.push_back(root);
        if(root == x) return true;

        if(root_to_leaf_path(root->left, x, ans) || root_to_leaf_path(root->right, x, ans)) return true;

        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        vector<TreeNode*> p1;
        vector<TreeNode*> p2;

        root_to_leaf_path(root, p, p1);
        root_to_leaf_path(root, q, p2);

        reverse(p1.begin(), p1.end());
        reverse(p2.begin(), p2.end());

        for(auto it1 : p1) {
            for(auto it2 : p2) {
                if(it1 == it2) return it1;
            }
        }
        return nullptr;
    }
};