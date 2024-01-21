class Solution
{
    public:
    int ans =0;
    int helper(Node *root){
        if(root==NULL)return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        ans += abs(l) + abs(r);
        return (l + r + root->key -1);
        
    }
    int distributeCandy(Node* root)
    {
        helper(root);
        return ans;
    }
};
