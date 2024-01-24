class Solution {
public:
    int ans =0;

    bool check(vector<int> & arr){
        int count =0;
        for(auto & it : arr){
            count += (it&1);
        }
        return count<=1;
    }

    void dfs(TreeNode *root , vector<int> & arr){
        if(root==NULL){
            if(check(arr))ans++;
            return;
        }
        if(!root->left && !root->right){
            arr[root->val]++;
            if(check(arr))ans++;
            arr[root->val]--;
            return;
        }
    
        arr[root->val]++;
        if(root->left){
            dfs(root->left , arr);
        }
        if(root->right){
            dfs(root->right , arr);
        }
        
        arr[root->val]--;
        
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> temper(10 , 0);
        dfs(root , temper);
        return ans;
    }
};
