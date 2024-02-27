class Solution {
public:
    pair <int,int> diameter(TreeNode *root){
        if(root==NULL)return {0 ,0};
        pair<int,int>left = diameter(root->left);
        pair <int,int> right = diameter(root->right);
        int d = left.first + right.first +1;
        return {1 + max(left.first , right.first) , max({d,left.second,right.second})};

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).second -1;
    }
};
