class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL && root2==NULL){
            return 1;
        }else if(root1==NULL || root2==NULL || (root1->data!=root2->data)){
            return 0;
        }
        return (isIsomorphic(root1->left , root2->left) && isIsomorphic(root1->right , root2->right)) || (isIsomorphic(root1->right , root2->left) && isIsomorphic(root1->left , root2->right));
    }
};
