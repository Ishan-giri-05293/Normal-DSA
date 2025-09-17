/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Make sure we don’t depend on order of p and q
        int pval = p->val;
        int qval = q->val;

        TreeNode* node = root;
        while (node) {
            int val = node->val;
            if (val > pval && val > qval) {
                // both p and q are in left subtree
                node = node->left;
            } else if (val < pval && val < qval) {
                // both p and q are in right subtree
                node = node->right;
            } else {
                // split point found, or one equals node
                return node;
            }
        }
        return nullptr;  // Should never happen if p and q are guaranteed in tree
    }
};
