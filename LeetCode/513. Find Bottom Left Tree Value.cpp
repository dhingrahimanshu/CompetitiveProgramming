
class Solution {
public:
    int ans =1 , depth =-1;
    void dfs(TreeNode *root , int d){
        if(root==NULL)return;
        if(d>depth){
            depth = d;
            ans = root->val;
        }
        dfs(root->left , d+1);
        dfs(root->right , d+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int a =0;
        dfs(root ,a);
        return ans;
    }
};
