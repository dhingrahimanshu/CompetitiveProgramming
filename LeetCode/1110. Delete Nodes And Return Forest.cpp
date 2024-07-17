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
    void helper(TreeNode * root,map<int,int> & tmp,vector<TreeNode*> &ans){
        if(!root)return ;
        if(tmp[root->val]){
            if(root->left){
                if(!tmp[root->left->val]){
                    ans.push_back(root->left);
                }   
                helper(root->left,tmp,ans);
            }
            if(root->right){
                if(!tmp[root->right->val]){
                    ans.push_back(root->right);

                }
                helper(root->right,tmp,ans);
            }
        
            return;
        }
        helper(root->left,tmp,ans);
        helper(root->right,tmp,ans);
        if(root->left && tmp[root->left->val]){
            root->left = NULL;
        }
        if(root->right && tmp[root->right->val]){
            root->right = NULL;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root)return {};
        vector<TreeNode*> ans;
        map <int,int> tmp;
        
        for(auto & it : to_delete){
            tmp[it]++;
        }
        if(!tmp[root->val]){
            ans.push_back(root);
        }
        helper(root,tmp,ans);
        return ans;
    }
};
