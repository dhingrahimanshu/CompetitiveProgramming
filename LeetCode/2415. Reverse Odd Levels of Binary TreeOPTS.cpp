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


/*
How to do it with DFS?
1. Keep level
2. We know the number of nodes at every level


*/
class Solution {
public:

    void helper (TreeNode* lc, TreeNode* rc, int level) {
        if (!lc || !rc) return;

        if (level % 2 == 0) {
            lc->val = (lc->val ^ rc->val);
            rc->val = (lc->val ^ rc->val);;
            lc->val = (lc->val ^ rc->val);
        }
        helper(lc->left, rc->right, level ^ 1);
        helper(lc->right, rc->left, level ^ 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        helper(root->left, root->right, 0);
        return root;
    }
};
