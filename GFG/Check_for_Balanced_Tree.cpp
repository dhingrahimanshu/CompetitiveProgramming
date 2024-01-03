class Solution{
    public:
    bool ans = true;
    
    
    int helper(Node * root){
        if(root==NULL){
            return 0;
        }
        int left = 1 + helper(root->left);
        int right = 1 + helper(root->right);
        if(abs(left-right)>1)ans = false;
        return max(left , right);
    }
    
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        helper(root);
       return ans;
    }
};
