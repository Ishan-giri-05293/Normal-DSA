/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int res = node->val;
        // after returning this node, its right subtree must be processed
        pushAllLeft(node->right);
        return res;
    }

    /** @return whether there is a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

private:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
};
