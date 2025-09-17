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
    void recoverTree(TreeNode* root) {
        // reset pointers
        first = nullptr;
        second = nullptr;
        pred = nullptr;

        // do in-order traversal to find the two bad nodes
        inorder(root);

        // swap the values of the two wrong nodes
        if (first && second) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }

private:
    TreeNode* pred;    // previously visited node in inorder
    TreeNode* first;   // first node to swap
    TreeNode* second;  // second node to swap

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);

        // check for violation
        if (pred && node->val < pred->val) {
            // if first violation, mark first = pred
            if (!first) {
                first = pred;
            }
            // always mark second = node on violation
            second = node;
        }

        pred = node;

        inorder(node->right);
    }
};
