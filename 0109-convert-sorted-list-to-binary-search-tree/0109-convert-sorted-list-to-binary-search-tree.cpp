/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(): val(0), next(nullptr) {}
 *     ListNode(int x): val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next): val(x), next(next) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        current = head;
        return build(0, n - 1);
    }

private:
    ListNode* current;

    int getLength(ListNode* node) {
        int len = 0;
        while (node) {
            ++len;
            node = node->next;
        }
        return len;
    }

    TreeNode* build(int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        // build left subtree first
        TreeNode* leftChild = build(l, mid - 1);

        // current points to the mid element
        TreeNode* root = new TreeNode(current->val);
        root->left = leftChild;

        // advance list pointer
        current = current->next;

        // build right subtree
        root->right = build(mid + 1, r);

        return root;
    }
};
