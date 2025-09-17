/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(): val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        acc = 0;
        reverseInorder(root);
        return root;
    }
private:
    int acc;  // running sum of greater (and equal) nodes

    void reverseInorder(TreeNode* node) {
        if (!node) return;
        // Visit right subtree first (nodes greater than current)
        reverseInorder(node->right);

        // Update current node
        acc += node->val;
        node->val = acc;

        // Visit left subtree
        reverseInorder(node->left);
    }
};
