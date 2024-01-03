class Solution{
  public:
    bool flag = false;
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(root==NULL){
            return NULL;
        }
        Node *a = inOrderSuccessor(root->left , x);
        if(flag){
            flag = false;
            return root;
        }
        if(root==x){
            flag = true;
        }
        
        Node *b =inOrderSuccessor(root->right , x);
        
        if(a){
            return a;
        }
        return b;
        
    }
};
