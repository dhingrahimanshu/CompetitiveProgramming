class Solution {
public:
    unordered_map <TreeNode * , int > dp;

    int helper(TreeNode *root){
        if(root==NULL)return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        int ans = helper(root->left) + helper(root->right);
        int ans2 =root->val;
        if(root->left){
            ans2 += helper(root->left->left) + helper(root->left->right);
        }
        if(root->right){
            ans2 += helper(root->right->left) + helper(root->right->right);
        }
        return dp[root]  = max(ans , ans2);

    }

    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        return helper(root);
    }
};
