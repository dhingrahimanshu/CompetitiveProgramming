class Solution{
    public:
    
    int isSumProperty(Node *root)
    {
        if(root==NULL)return 1;
        if(!root->left && !root->right)return 1;
        int left = isSumProperty(root->left);
        int right = isSumProperty(root->right);
        int ans =0;
        if(root->left){
            ans += root->left->data;
        }
        if(root->right){
            ans += root->right->data;
        }
        return (ans==root->data && left && right);
    }
};
