class Solution {
public:

    int helper(TreeNode *root , int &ans){
        if(root==NULL)return 0;
        int left = helper(root->left , ans);
        int right = helper(root->right ,ans);
        ans += (abs(left) + abs(right));
        return (left + right + root->val -1);
    }

    int distributeCoins(TreeNode* root) {
        int ans =0;
        helper(root ,ans);
        return ans;
    }
};
