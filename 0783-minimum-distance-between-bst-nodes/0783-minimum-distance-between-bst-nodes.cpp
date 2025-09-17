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
    int minDiffInBST(TreeNode* root) {
        prev_val = -1;  // mark “no previous” yet
        ans = INT_MAX;
        inorder(root);
        return ans;
    }

private:
    int prev_val;
    int ans;

    void inorder(TreeNode* node) {
        if (!node) return;
        // traverse left
        inorder(node->left);

        // process current
        if (prev_val >= 0) {
            ans = min(ans, node->val - prev_val);
        }
        prev_val = node->val;

        // traverse right
        inorder(node->right);
    }
};
