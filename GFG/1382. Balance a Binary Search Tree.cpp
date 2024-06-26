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
    vector<int> bst;
    void helper(TreeNode * root){
        if(!root)return ;
        helper(root->left);
        bst.push_back(root->val);
        helper(root->right);
    }
    TreeNode *makeBst(int left, int right){
        if(left > right){
            return NULL;
        }
        if(left == right){
            return new TreeNode(bst[left]);
        }
        int mid = (left + right)/2;
        TreeNode *root = new TreeNode(bst[mid]);
        root->left = makeBst(left, mid-1);
        root->right = makeBst(mid+1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        helper(root);
        return makeBst(0, bst.size() - 1);
    }
};
