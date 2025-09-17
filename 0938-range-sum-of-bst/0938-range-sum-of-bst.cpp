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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }

private:
    int dfs(TreeNode* node, int low, int high) {
        if (!node) return 0;
        
        // If node's value is less than low, ignore left subtree
        if (node->val < low) {
            return dfs(node->right, low, high);
        }
        
        // If node's value is greater than high, ignore right subtree
        if (node->val > high) {
            return dfs(node->left, low, high);
        }
        
        // Otherwise, node is in [low, high]
        return node->val 
             + dfs(node->left, low, high) 
             + dfs(node->right, low, high);
    }
};
