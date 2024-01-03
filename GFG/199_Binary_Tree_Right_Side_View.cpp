class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        queue <TreeNode *> pending;
        vector<int> ans;
        
        pending.push(root);
        while(pending.size()){
            int n  = pending.size();
            int temp =-1;
            for(int i =0 ;i<n;i++){
                TreeNode *f = pending.front(); pending.pop();
                temp = f->val;
                if(f->left){
                    pending.push(f->left);
                    
                }
                if(f->right){
                    pending.push(f->right);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
