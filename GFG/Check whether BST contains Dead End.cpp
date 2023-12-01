class Solution{
  public:
    
    bool helper(Node *root , int mi , int ma){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL){
            if(ma-mi <= 2){
                return 1;
            }
            return 0;
        }
        return helper(root->left ,mi  , root->data)|helper(root->right , root->data ,ma);
    }
  
    bool isDeadEnd(Node *root)
    {
        return helper(root , 0 , INT_MAX);
    }
};
