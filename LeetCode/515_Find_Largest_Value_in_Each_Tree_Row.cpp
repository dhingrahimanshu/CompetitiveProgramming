class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        vector<int> ans;
        queue <TreeNode*> pending;
        pending.push(root);

        while(pending.size()){
            int ma = INT_MIN;
            int n = pending.size();
            for(int i =0 ;i<n;i++){
                TreeNode *cur = pending.front(); pending.pop();
                ma = max(ma , cur->val);
                if(cur->left){
                    pending.push(cur->left);
                }
                if(cur->right){
                    pending.push(cur->right);
                }
            }
            ans.push_back(ma);
        }
        return ans;
    }
};
