/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(): val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
 * };
 */

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        TreeNode* prev = nullptr;
        int currentCount = 0;
        int maxCount = 0;
        inorder(root, prev, currentCount, maxCount, ans);
        return ans;
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev,
                 int& currentCount, int& maxCount, vector<int>& ans) {
        if (!node) return;
        inorder(node->left, prev, currentCount, maxCount, ans);

        // Process current node
        if (prev && prev->val == node->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            ans.clear();
            ans.push_back(node->val);
        } else if (currentCount == maxCount) {
            ans.push_back(node->val);
        }

        prev = node;

        inorder(node->right, prev, currentCount, maxCount, ans);
    }
};
