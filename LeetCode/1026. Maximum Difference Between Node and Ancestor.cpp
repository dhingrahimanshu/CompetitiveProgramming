class Solution {
public:
    int ans =0;

    pair<int,int> helper(TreeNode *root){
        int data = root->val;
        pair<int,int> ans2 = {data , data};
        if(root->left){
            pair<int,int> temp = helper(root->left);
            ans=max({ans , abs(data - temp.first) , abs(data - temp.second)});
            ans2.first = min(data , temp.first);
            ans2.second = max(data , temp.second);
        }
        if(root->right){
            pair<int,int> temp = helper(root->right);
            ans=max({ans , abs(data - temp.first) , abs(data - temp.second)});
            ans2.first = min(ans2.first , temp.first);
            ans2.second = max(ans2.second , temp.second);
        }
        return ans2;
    }

    int maxAncestorDiff(TreeNode* root) {
        helper(root);
        return ans;
    }
};
